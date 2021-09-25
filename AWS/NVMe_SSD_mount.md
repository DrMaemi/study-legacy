# AWS EC2 인스턴스에 NVMe SSD 마운트
- [Linux 인스턴스 Amazon EBS 및 NVMe 마운트 공식 설명서](https://docs.aws.amazon.com/ko_kr/AWSEC2/latest/UserGuide/nvme-ebs-volumes.html)

## 1. 인스턴스 NVMe 드라이버 확인
```
$ modinfo nvme
name:           nvme
filename:       (builtin)
version:        1.0
license:        GPL
author:         Matthew Wilcox <willy@linux.intel.com>
parm:           use_threaded_interrupts:int
parm:           use_cmb_sqes:use controller's memory buffer for I/O SQes (bool)
parm:           max_host_mem_size_mb:Maximum Host Memory Buffer (HMB) size per controller (in MiB) (uint)
parm:           sgl_threshold:Use SGLs when average request segment size is larger or equal to this size. Use 0 to disable SGLs. (uint)
parm:           io_queue_depth:set io queue depth, should >= 2
parm:           write_queues:Number of queues to use for writes. If not set, reads and writes will share a queue set. (uint)
parm:           poll_queues:Number of queues to use for polled IO. (uint)
```
<br>

### 1.1. NVMe 드라이버 업데이트
- Amazon Linux 2, Amazon Linux, CentOS 및 Red Hat Enterprise Linux:
    ```
    $ sudo yum update -y
    ```
- Ubuntu 및 Debian:
    ```
    $ sudo apt-get update -y
    ```

- Ubuntu 16.04 이상
    ```
    $ sudo apt-get install --only-upgrade -y linux-aws
    ```

- Ubuntu 14.04
    ```
    $ sudo apt-get install linux-aws
    ```
이후 재부팅
```
sudo reboot
```

## 2. NVMe EBS 디바이스 식별
```
$ lsblk
NAME        MAJ:MIN RM   SIZE RO TYPE MOUNTPOINT
loop0         7:0    0  33.3M  1 loop /snap/amazon-ssm-agent/3552
loop1         7:1    0  32.3M  1 loop /snap/snapd/11588
loop2         7:2    0  70.4M  1 loop /snap/lxd/19647
loop3         7:3    0  55.5M  1 loop /snap/core18/1997
nvme1n1     259:0    0 209.6G  0 disk
nvme0n1     259:1    0    20G  0 disk 
└─nvme0n1p1 259:2    0    20G  0 part /
```
<br>

- [NVMe EBS 볼륨 포맷 및 탑재 공식 설명서](https://docs.aws.amazon.com/ko_kr/AWSEC2/latest/UserGuide/ebs-using-volumes.html)

## 3. 볼륨 포맷
`lsblk` 명령어로 살펴봤을 때 아직 연결되지 않은 볼륨은 `/dev/nvme1n1`이다.
<p>

볼륨 파일 시스템 확인
```
$ sudo file -s /dev/nvme1n1
/dev/nvme1n1: data
```
위와 같이 출력에 `data`만 표시된다면, 해당 디바이스에 파일 시스템이 없는 것이다.
</p>
<p>

인스턴스에 연결된 모든 디바이스 정보 보기
```
$ sudo lsblk -f
sudo lsblk -f
NAME   FSTYPE LABEL      UUID                                 FSAVAIL FSUSE% MOUNTPOINT
loop0  squash                                                       0   100% /snap/amaz
loop1  squash                                                       0   100% /snap/snap
loop2  squash                                                       0   100% /snap/lxd/
loop3  squash                                                       0   100% /snap/core
nvme1n1
                                                                             
nvme0n1
│                                                                            
└─nvme0n1p1
       ext4   cloudimg-rootfs
                         e8070c31-bfee-4314-a151-d1332dc23486    8.6G    55% /
```
</p>
<p>

우분투 인스턴스의 루트 볼륨 파일 시스템과 같은 ext4로 NVMe SSD 볼륨 포맷하기
```

$ sudo mkfs -t ext4 /dev/nvme1n1
mke2fs 1.45.5 (07-Jan-2020)
Discarding device blocks: done                            
Creating filesystem with 54931640 4k blocks and 13737984 inodes
Filesystem UUID: 69a29f9d-c076-421f-880a-601fab8f07a4
Superblock backups stored on blocks: 
        32768, 98304, 163840, 229376, 294912, 819200, 884736, 1605632, 2654208, 
        4096000, 7962624, 11239424, 20480000, 23887872

Allocating group tables: done                            
Writing inode tables: done                            
Creating journal (262144 blocks): done
Writing superblocks and filesystem accounting information: done
```
</p>
<p>

포맷 확인
```
$ sudo file -s /dev/nvme1n1
/dev/nvme1n1: Linux rev 1.0 ext4 filesystem data, UUID=69a29f9d-c076-421f-880a-601fab8f07a4 (extents) (64bit) (large files) (huge files)
```
</p>
<p>

다시 인스턴스에 연결된 디바이스 정보를 보면, 볼륨에 `UUID`가 부여됐음을 확인할 수 있다.
```
$ sudo lsblk -f
NAME   FSTYPE LABEL      UUID                                 FSAVAIL FSUSE% MOUNTPOINT
loop0  squash                                                       0   100% /snap/amaz
loop1  squash                                                       0   100% /snap/snap
loop2  squash                                                       0   100% /snap/lxd/
loop3  squash                                                       0   100% /snap/core
nvme1n1
       ext4              69a29f9d-c076-421f-880a-601fab8f07a4                
nvme0n1
│                                                                            
└─nvme0n1p1
       ext4   cloudimg-rootfs
                         e8070c31-bfee-4314-a151-d1332dc23486    8.6G    55% /
```
</p>
<p>

혹은, `sudo blkid` 명령어를 통해 간단히 확인 가능
```
$ sudo blkid
/dev/nvme0n1p1: LABEL="cloudimg-rootfs" UUID="e8070c31-bfee-4314-a151-d1332dc23486" TYPE="ext4" PARTUUID="5198cbc0-01"
/dev/loop0: TYPE="squashfs"
/dev/loop1: TYPE="squashfs"
/dev/loop2: TYPE="squashfs"
/dev/loop3: TYPE="squashfs"
/dev/nvme1n1: UUID="69a29f9d-c076-421f-880a-601fab8f07a4" TYPE="ext4"
```
</p>

<br>

## 3. 볼륨 탑재(마운트)
<p>

탑재 지점 디렉토리 생성
```
$ sudo mkdir /ssd
```
</p>
<p>

마운트
```
sudo mount /dev/nvme1n1 /ssd
```
</p>
<p>

다음과 같이 탑재가 잘 됐는지 확인
```
$ df -h
Filesystem      Size  Used Avail Use% Mounted on
/dev/root        20G   11G  8.7G  56% /
devtmpfs         16G     0   16G   0% /dev
tmpfs            16G     0   16G   0% /dev/shm
tmpfs           3.1G  896K  3.1G   1% /run
tmpfs           5.0M     0  5.0M   0% /run/lock
tmpfs            16G     0   16G   0% /sys/fs/cgroup
/dev/loop0       34M   34M     0 100% /snap/amazon-ssm-agent/3552
/dev/loop1       33M   33M     0 100% /snap/snapd/11588
/dev/loop2       71M   71M     0 100% /snap/lxd/19647
/dev/loop3       56M   56M     0 100% /snap/core18/1997
tmpfs           3.1G  4.0K  3.1G   1% /run/user/1000
/dev/nvme1n1    206G   61M  195G   1% /ssd
```
</p>

### 3.1. 재부팅 후 연결 볼륨 자동 탑재
<p>

```
$ sudo vim /etc/fstab
```
</p>
<p>

해당 파일에 다음 내용 추가
```
UUID=<UUID> <mount dir> <format> <options> <options values>
```
예시
```
UUID=69a29f9d-c076-421f-880a-601fab8f07a4 /ssd ext4 defaults,nofail 0 2
```
</p>
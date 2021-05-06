mkdir -p /home/drmaemi/github-repos/docker-study/html
echo "Web server running: YES" > /home/drmaemi/github-repos/docker-study/html/index.html
docker run -d -p 80:80 --name=my_web_server -v /home/drmaemi/github-repos/docker-study/html/:/usr/share/nginx/html nginx
curl http://localhost:80

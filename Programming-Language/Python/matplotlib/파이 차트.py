import matplotlib.pyplot as plt

# 기본
ratio = [34, 32, 16, 18]
labels = ['Apple', 'Banana', 'Melon', 'Grapes']

# plt.pie(ratio, labels=labels, autopct='%.1f%%')
plt.pie(ratio, labels=labels, autopct='%.0f%%')
plt.show()

# 부채꼴 스타일 지정
colors = ['#ff9999', '#ffc000', '#8fd9b6', '#d395d0']

# 부채꼴 영역의 스타일을 설정
# width: 부채꼴 영역 너비(반지름 비율)
# edgecolor: 테두리 색상
# linewidth: 테두리 선 너비
wedgeprops={'width': 0.7, 'edgecolor': 'w', 'linewidth': 5}


plt.pie(ratio, labels=labels, autopct='%.1f%%', startangle=260, counterclock=False, colors=colors, wedgeprops=wedgeprops)
plt.show()

ratio = [99, 1]
labels = ['installed', '']
colors = ['#8fd9b6', '#d395d0']
plt.pie(ratio, labels=labels, autopct='%.1f%%', startangle=260, counterclock=False, colors=colors, wedgeprops=wedgeprops)
plt.show()
"""
---------------------------------------------------------
题目：有四个数字：1、2、3、4，能组成多少个互不相同且
无重复数字的三位数？各是多少？

程序分析：可填在百位、十位、个位的数字都是1、2、3、4。
组成所有的排列后再去掉不满足条件的排列。
---------------------------------------------------------
"""

number_list = [value for value in range(1,5)]
new_number_list = []

for g in number_list:
	for s in number_list:
		for b in number_list:
			if g != s and g != b and s != b:
				new_number_list.append(g + s*10 + b*100)
for number in sorted(new_number_list):
	print(number)

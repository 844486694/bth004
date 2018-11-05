# -*- coding: utf-8 -*-
# @Time    : 2018/10/27 22:06
# @Author  : 201619630303_杜天启
# @FileName: knapsack_NS.py
# @Software: PyCharm
from item import item
from util import *
from copy import *

item_list=[]
value_list=[20,10,12,23,40,5]
weight_list=[15,12,13,16,30,5]
bag_constrain_list=[35,30]
length=len(value_list)
visit=[False]*length
solutions=[[0 for i in range(length)] for j in range(len(bag_constrain_list))]


def neighborhood(n):
	init = [0 for i in range(length)]
	for  x in range(len(bag_constrain_list)):
		pre_value = 0
		if_break=True
		while if_break:
			#访问邻域
			tmp = deepcopy(init)
			# 邻域中最大的
			max=deepcopy(init)

			for y in range(n):
				if init[y] is 0and visit[y]is False:
					tmp[y]=1
				elif init[y]is 1and visit[y]is False:
					tmp[y]=0
				w = 0
				values = 0
				# 计算tmp的价值和重量
				for z in range(n):
					if visit[z] is False:
						values+=tmp[z]*item_list[z].value
						w+=tmp[z]*item_list[z].weight
				# 超出容量
				if w>bag_constrain_list[x]:
					if_break=False
					tmp = deepcopy(init)
					continue
				if values>pre_value :
					max=deepcopy(tmp)
					pre_value=values
					if_break=True
				else:
					if_break=False
				tmp = deepcopy(init)
			init=deepcopy(max)
		for i in range(n):
			if init[i]==1:
				visit[i]=True
				if x==0:
					solutions[x][i]=1
				else:
					t=init[i]
					for m in range(x-1,-1,-1):
						t-=solutions[m][i]
					solutions[x][i]=t
					
bag_constrain_list.sort(reverse=True)

for i in range(length):
	t_item=item(value_list[i],weight_list[i])
	item_list.append(t_item)
	# print(item_list[i].value,item_list[i].weight)

benefit_per_weight_sort(item_list)
neighborhood(length)

print("solution:")
for l in solutions:
	for e in l:
		print(e,end=" ")
	print()
for l in range(len(bag_constrain_list)):
	print("bag", l+1, "volume:", bag_constrain_list[l])
	
	values = 0
	for i in range(len(solutions[l])):
		if solutions[l][i] is 1:
			print("item", i+1, "value:", item_list[i].value, "weight:", item_list[i].weight)
		values += solutions[l][i] * item_list[i].value
	
	print(values)
	

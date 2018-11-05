# -*- coding: utf-8 -*-
# @Time    : 2018/10/30 21:17
# @Author  : 201619630303_杜天启
# @FileName: knapsack_NS_new.py
# @Software: PyCharm

from item import item
from util import *
from copy import *
import numpy as np

item_list = []
value_list = [20, 10, 12, 23, 40, 5,80,50,1,90,150]
weight_list = [15, 12, 13, 16, 30, 5,80,50,1,80,120]
bag_constrain_list = [100, 150]
length = len(value_list)
visit = [False] * length
solutions = [[0 for i in range(length)] for j in range(len(bag_constrain_list))]


def neighborhood(solutions):
	max=0
	is_break=True
	while is_break:
		record = deepcopy(solutions)
		tmp = deepcopy(solutions)
		# 访问邻域
		is_break=False
		for i in range(len(bag_constrain_list)):
			for j in range(length):
				axis_sum=np.sum(tmp,axis=0)
				if solutions[i][j] == 1:
					tmp[i][j]=0
				elif solutions[i][j]== 0 and axis_sum[j]== 0:
					tmp[i][j]=1
				elif solutions[i][j]== 0 and axis_sum[j]== 1:
					continue
				total_value=0
				slt_break=False
				for x in range(len(bag_constrain_list)):
					if slt_break is True:
						break
					current_value = 0
					current_weight = 0
					for y in range(length):
						current_weight+=item_list[y].weight*tmp[x][y]
						current_value+=item_list[y].value*tmp[x][y]
					if current_weight>bag_constrain_list[x]:
						slt_break=True
						total_value=0
						break
					else:
						total_value+=current_value
				
				if total_value>max:
					is_break=True
					max=total_value
					record=deepcopy(tmp)

				tmp=deepcopy(solutions)
		solutions=record
	return solutions


bag_constrain_list.sort(reverse=True)

for i in range(length):
	t_item = item(value_list[i], weight_list[i])
	item_list.append(t_item)
# print(item_list[i].value,item_list[i].weight)

benefit_per_weight_sort(item_list)
solutions=neighborhood(solutions)

print("solutions:")
for l in solutions:
	for e in l:
		print(e, end=" ")
	print()
for l in range(len(bag_constrain_list)):
	print("bag", l + 1, "volume:", bag_constrain_list[l])
	
	values = 0
	for i in range(len(solutions[l])):
		if solutions[l][i] is 1:
			print("item", i , "value:", item_list[i].value, "weight:", item_list[i].weight)
		values += solutions[l][i] * item_list[i].value
	
	print(values)


# -*- coding: utf-8 -*-
# @Time    : 2018/10/27 18:00
# @Author  : 201619630303_杜天启
# @FileName: knapsack_greedy.py
# @Software: PyCharm
from item import item
from util import  *
from copy import*


def greedy(l):
	for i in range(len(bag_constrain_list)):
		for j in range(l):
			if item_list[j].weight>bag_constrain_list[i]:
				continue
			if visit_list[j] is False:
				visit_list[j]=True
				solutions[i][j]=1
				bag_constrain_list[i] -= item_list[j].weight


item_list=[]
value_list = [20, 10, 12, 23, 40, 5, 80, 50, 1, 90, 150,2000,1000]
weight_list = [15, 12, 13, 16, 30, 5, 80, 50, 1, 80, 120,150,99]
bag_constrain_list = [100, 150]
visit_list=[False]*len(value_list)
solutions=[[0 for i in range(len(value_list))] for j in range(len(bag_constrain_list))]
bag_constrain_list.sort(reverse=True)
volumes=deepcopy(bag_constrain_list)
for i in range(value_list.__len__()):
	tmp=item(value_list[i],weight_list[i])
	item_list.append(tmp)
	# print(item_list[i].value,item_list[i].weight)


benefit_per_weight_sort(item_list)
greedy(len(item_list))

cnt=1
print("solutions:")
for l in solutions:
	for e in l:
		print(e, end=" ")
	print()
for l in range(len(bag_constrain_list)):
	print("bag" , cnt,"volume:",volumes[l])
	cnt+=1
	values = 0
	for i in range(len(solutions[l])):
		if solutions[l][i] is 1:
			print("item",i,"value:",item_list[i].value,"weight:",item_list[i].weight)
		values+=solutions[l][i]*item_list[i].value
	
	print(values)


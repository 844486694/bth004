# -*- coding: utf-8 -*-
# @Time    : 2018/10/27 21:03
# @Author  : 201619630303_杜天启
# @FileName: util.py
# @Software: PyCharm


def benefit_per_weight_sort(list):
	for i in range(len(list)):
		for index in range(i,len(list)):
			if list[i].benefit_per_wieght<list[index].benefit_per_wieght:
				list[i],list[index]=list[index],list[i];
	
	return list
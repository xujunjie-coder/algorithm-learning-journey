import pandas as pd
import numpy as np
import scipy.stats as stats
from mlxtend.frequent_patterns import apriori, association_rules

# 1. 数据预处理
# 假设 df_sales 是读取的附件2销售流水明细数据
# 包含列: ['销售日期', '扫码销售时间', '单品编码', '单品名称', '分类名称', '销量(千克)']
df_sales = pd.read_csv('sales_data.csv') 
df_sales['销售日期'] = pd.to_datetime(df_sales['销售日期'])

# 按日和品类聚合销量
daily_category_sales = df_sales.groupby(['销售日期', '分类名称'])['销量(千克)'].sum().unstack(fill_value=0)

# 2. 分布规律分析 (以正态分布拟合和K-S检验为例)
distribution_results = {}
for category in daily_category_sales.columns:
    data = daily_category_sales[category]
    # 描述性统计
    mean, std = data.mean(), data.std()
    # 正态分布拟合与K-S检验
    stat, p_value = stats.kstest(data, 'norm', args=(mean, std))
    distribution_results[category] = {'Mean': mean, 'Std': std, 'KS_stat': stat, 'p_value': p_value}

# 3. 相互关系分析 - 相关系数矩阵 (Pearson)
correlation_matrix = daily_category_sales.corr(method='pearson')

# 4. 相互关系分析 - 关联规则挖掘 (Apriori)
# 将流水数据转换为 Transaction 矩阵 (按订单号/扫码时间合并)
basket = df_sales.groupby(['扫码销售时间', '分类名称'])['销量(千克)'].sum().unstack(fill_value=0)
basket_sets = basket.applymap(lambda x: 1 if x > 0 else 0)

# 生成频繁项集和关联规则
frequent_itemsets = apriori(basket_sets, min_support=0.05, use_colnames=True)
rules = association_rules(frequent_itemsets, metric="lift", min_threshold=1.0)
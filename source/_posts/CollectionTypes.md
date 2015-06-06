title: 集合类型（Collection Types）
tags: [Array,Set,Dictionary]
categories: [Swift]

---

##数组
可以存储多个`类型相同`的值。不同于oc中的NSArray和NSMutableArray
###两种声明方式
1. `var ary :Array<String>`
2. `var ary :[String]`
3. `var ary = [Int]()` 声明并初始化且元素为空
4. `var ary = [String](count: 5, repeatedValue: "empty")` 指定元素个数与初始值
5. `var ary = Array(count: 5, repeatedValue: "empty")`

###构造

```
["",""]

```

###访问和修改
count

isEmpty

append()

+

+=

[]下标访问与修改

[]修改区间段的值

Note:不可以使用下标在数组末尾添加新项

insert(data,atIndex:index) 在index索引之前添加数据data

removeAtIndex(index) 移除指定位置的数据并返回改数据

removeLast()

遍历数组

1. for element in array
2. for (index,value) in enumerate(array)
enumerate返回数组每项元素的索引和值


##集合
用来存储相同类型并且没有确定顺序的值。当元素顺序不重要或者希望确保每个元素只出现一次时可以考虑使用集合。
###语法
1. `var sets = Set<String>()`
2. `var sets: Set<String> = ["","”]` 可以简化为`var sets: Set = ["","”]`

###访问和修改
count 

isEmpty

insert

remove如果值存在则删除并返回该值，否则返回nil

contains检查set中是否包含一个特定的值

遍历与数组相同

因为set没有顺序，如果需要按照特定顺序来遍历一个set中的值可以使用全局sorted函数
```
var sets :Set = ["1","2","3"]

for str in sorted(sets){
    println(str)
}
```

union() 合并两个集合剔除重复的元素

sets1.subtract(sets2) sets1中的元素且不在sets2中出现

intersect() 两个集合中都包含的值集合

exclusiveOr() 两个集合中不重复的元素集合

集合间比较

1. = 比较集合是否包含相同的元素
2. setsb.isSubsetOf(setsa) 		setsb是否是setsa的子集（两个集合可以相等）
3. setsa.issupersetOf(setsb) 	setsa是否是setsb的父集（两个集合可以相等）
4. isStrictSubsetOf()或者isStrictSupersetOf()功能与上面两个函数功能相同（两个集合不能相等）
5. isDisjoinWith()  判断两个集合是否完全不相同（没有一个相同的元素）

###Set类型的哈希值


##字典
字典是一种存储多个相同类型的值得容器。每个值都关联唯一的键，键作为字典中的这个值数据的标示符。无序

Note:keyType的唯一的要求就是可哈希的。

###字面量
var dicts:[String:String] = ["name":"dict","age":"10"] 可以简化为 var dicts = ["name":"dict","age":"10"]

###操作字典

count

isEmpty

修改值的两种方式

1. 下标操作
	下标操作可以为字典添加元素，这点不同于数组。也可以设置为nil移除键值对
2. updateValue(forKey:) 此方法可以设置或者更新特定键对应的值。不过它会返回此键的原值
3. removeValueForKey()同样会返回移除的值，如果不存在值的情况会返回nil


+ 字典遍历
for-in 遍历字典通常会将键值对以元组的形式返回，我们可以分解元组

```
var dict = ["a":"1","b":"2"]
for (key,value) in dict{
	println("key:"+key+" value:"+value)
}
```

我们还可以使用它的keys和values属性遍历

```
for key in dict.keys{
	println("key:"+key)
}

```
	
Array(dict.keys)

创建空字典 var dict = Dictionary<Int,Int>()
如果字典已经有了类型信息我们可以空字典字面量来创建一个空字典[:]
dict = [:]






















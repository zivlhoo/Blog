title: Closures
date: 2015-06-06 15:33:49
tags: [闭包,尾随闭包]
categories: [Swift]

---

闭包是包含函数代码块，可以在代码中被传递和使用。与c++的lambda类似。

###闭包有三种形式
1. 全局函数：有名字但不会捕获任何值的闭包
2. 嵌套函数：有名字，只捕获其封闭函数区域内的值的闭包
3. 闭包表达式：利用轻量级语法，可以捕获其上下文中变量或常量值的匿名闭包

##闭包表达式

```
{
	(parameters) -> returnType in
		statements
}
```

闭包参数不可以使用默认值，其他和函数参数规则没有区别。

```
sorted(	[4,3,2,1,0], 
				{
					(s1:Int,s2:Int)->Bool in 
						return s1 > s2
				}
			)
```

###根据上下文自动推断类型
如果闭包是作为参数传入函数的，Swift就可以推断出其`参数`与`返回值`的类型。因此可以精简如下:

```
sorted([4,3,2,1,0], {s1,s2 in return s1 < s2})
```
###单行表达式闭包隐式返回
`单行`表达式闭包可以省略`return`关键字来隐式返回表达式结果。再精简

```
sorted([4,3,2,1,0], {s1,s2 in s1 < s2})
```
单行指的是闭包体代码及 `s1 < s2`

另外整个闭包也不是一定要在一行书写完成。如下例子也是正确的：

```
sorted([4,3,2,1,0], {s1,s2 in 
								s1 < s2
							}
		)
```

###参数名称缩写
Swift自动为内联函数提供了参数名称缩写功能，可以直接使用$0,$1,$2来顺序调用闭包的参数。再精简

```
sorted([4,3,2,1,0], {$0 < $1})
```

###运算符函数
Swift的`Int`类型定义了关于`<`的数字实现，其被定义为一个函数接受两个`Int`类型的参数并返回`Bool`类型的值。而这正好与sorted函数的第二个参数需要的函数类型相符合。最后精简:

```
sorted([4,3,2,1,0], <)
```

##尾随闭包
尾随闭包是一种书写在函数括号之后的闭包表达式。如果将闭包表达式作为函数的末尾参数，可以使用尾随闭包来增强函数的可读性。

首先定义个函数

```
func test(fun:()->String)
{
    println("call fun result \(fun())")
}

```

使用尾随闭包调用

```
test(){return "test"}
```

如果函数只需要闭包表达式一个参数，可以省略掉括号

```
//只有一个闭包参数省略括号
test{return "test"}

//使用尾随闭包改写排序
sorted([1,2,3,4,5,6]){$0 > $1}
```
```
let digitNames = [ 0: "Zero", 1: "One", 2: "Two", 3: "Three", 4: "Four", 5 : "Five",6:"Six",7:"Seven",8:"Eight",9:"Nine"]

let numbers = [10,465,987]

var strings = numbers.map{
    (var number)->String in
    	var output = ""
    	while number > 0{
    		output = digitNames[number % 10]! + output
        number/=10
    	}
    	return output
}

println(strings)
```
##值捕获


##闭包是引用类型



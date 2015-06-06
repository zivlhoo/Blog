title: 枚举（Enumerations）
date: 2015-06-06 20:45:41
tags: [枚举]
categories: [Swift]

---

枚举定义了一个通用类型的一组相关的值，使你可以在你的代码中以一种安全的方式来使用这些值。

Swift中得枚举比较灵活，不必给每一个枚举成员提供一个值，如果一个值提供给每个枚举成员，则该值可以是一个字符串，字符，整形，浮点型。枚举成员可以指定任何类型的相关值存储到枚举成员中。

枚举也可以定义计算型属性，方法，构造函数，扩展功能，遵守协议。

##枚举语法
使用`enum`关键字，所有的枚举体放在一对大括号内：

```
enum CompassPoint{
	case North
	case South
	case East
	case West
}
```

Note:Swift的枚举成员在被定义是不会被赋予一个默认的整数值。

多个枚举成员可以出现在同一个case中，之间使用,号隔开。

```
enum CompassPoint{
	case North,	 South, East, West
}
```



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
	case North, South, East, West
}
```

命名规范：以大写字母开头，用一个单数名词而不是复数名词，以便阅读起来更加容易理解。

一旦变量被确定为枚举类型，就可以使用更简短的`.`语法为其设置枚举值

```
var enu:CompassPoint = .North
```

##匹配枚举值

可以用switch语句匹配枚举值

```
switch enu{
case .North:
    println("North")
case .South:
    println("South")
case .East:
    println("East")
case .West:
    println("West") 
}
```

`NOTE`:当switch用来匹配枚举值时，switch语句必须全面。如果忽略了其中的某一枚举值则无法通过编译。

##相关值

Swift的枚举可以存储任何类型的相关值，且每个相关值的数据类型也可以是各不相同的。

```
enum Barcode{
    case UPCA(Int,Int,Int)
    case QRCode(String)
}

var productBarcode = Barcode.UPCA(10, 10, 10)

productBarcode = .QRCode("test")


switch productBarcode{
case .QRCode(var str):
    println(str)
case var .UPCA(a, b, c):
    println(a)
    println(b)
    println(c)
}
```

`NOTE`:如果枚举成员的所有相关值被提取为常量或者变量，为了简洁，可以只放置一个`var`或者`let`标注在成员名称前。如`case var .UPCA(a, b, c):`

##原始值
作为相关值的替代，枚举成员可以被默认值（称为原始值）预先填充，其中这些原始值具有相同的类型。

```
enum ASCIIControlCharacter:Character{
    case Tab="\t"
    case LineFeed="\n"
    case CarriageReturn="\r"
}
```

###原始值与相关值的区别
+ 原始值

	定义枚举的时候，原始值是被预先填充的值，像上述三个ASCLL码。对于一个特定的枚举成员，它的原始值始终是相同的。
+ 相关值

	当你创建一个基于枚举成员的量是才会被设置，并且值可以设置成不同的。
	
原始值可以是字符串，字符，或者任何整型或者浮点型。每个原始值在它的枚举声明中必须是`唯一`的。当整型被用作原始值时，如果其他枚举成员没有值时，他们会自动递增。

枚举成员的`rawValue`属性可以访问该枚举成员的原始值。

可以通过`rawValue`构造函数创建特定原始值得枚举。

```
var a = ASCIIControlCharacter(rawValue: "\t")
```

枚举的构造函数返回的是可选的枚举成员，需要对其进行`可选绑定`。


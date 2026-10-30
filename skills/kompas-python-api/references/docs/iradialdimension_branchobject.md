# BranchObject - Опорный объект для дополнительного ответвления

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Размеры ](bb2356896.html) > [Интерфейс IRadialDimension ](iradialdimension.html) > [IRadialDimension - свойства ](iradialdimension_props.html) |  Scroll [ [ [ ](iradialdimension_dimensiontype.html "К следующему разделу")](iradialdimension_props.html "На уровень выше")](iradialdimension_branchscount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iradialdimension.html)

Тип данных: интерфейс [IDrawingObject](idrawingobject.html)

Синтаксис Automation:

BranchObject = Object.BranchObject( Index ) | Получить свойство([* ](1.html))  
---|---  
Object.BranchObject( Index ) = BranchObject | Установить свойство ([* ](1.html))  
BranchObject = Object.GetBranchObject( Index ) | Получить свойство ([**](2.html))  
Object.SetBranchObject( Index, BranchObject ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_BranchObject( Index, &BranchObject ) | Получить свойство  
---|---  
Object.put_BranchObject( Index, BranchObject ) | Установить свойство  
  
Входные параметры:

long Index - номер ответвления.

Свойство позволяет устанавливать и получать объект, на который указывает ответвление.

Подразделы:

(отсутствуют)

# BranchBegin - Начало ответвления

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Размеры ](bb2356896.html) > [Интерфейс IRadialDimension ](iradialdimension.html) > [IRadialDimension - свойства ](iradialdimension_props.html) |  Scroll [ [ [ ](iradialdimension_branchscount.html "К следующему разделу")](iradialdimension_props.html "На уровень выше")](iradialdimension_baseobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iradialdimension.html)

Тип данных: BOOL

Синтаксис Automation:

BranchBegin = Object.BranchBegin( Index ) | Получить свойство([* ](1.html))  
---|---  
Object.BranchBegin( Index ) = BranchBegin | Установить свойство ([* ](1.html))  
BranchBegin = Object.GetBranchBegin( Index ) | Получить свойство ([**](2.html))  
BranchBegin = Object.GetBranchBegin( Index ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_BranchBegin( Index, &BranchBegin ) | Получить свойство  
---|---  
Object.put_BranchBegin( Index, BranchBegin ) | Установить свойство  
  
Входные параметры:

long Index - номер ответвления

Значения свойства:

TRUE | \- от начала полки,  
---|---  
FALSE | \- от конца полки.  
  
Подразделы:

(отсутствуют)

# AddBranch - Добавить ответвление для объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Размеры ](bb2356896.html) > [Интерфейс IRadialDimension ](iradialdimension.html) > [IRadialDimension - методы ](iradialdimension_methods.html) |  Scroll [ [ [ ](iradialdimension_addbranchbyarcparam.html "К следующему разделу")](iradialdimension_methods.html "На уровень выше")](iradialdimension_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iradialdimension.html)

Синтаксис Automation:

BOOL AddBranch( BOOL BranchBegin,

IDrawingObject * BranchObject );

Синтаксис COM:

HRESULT AddBranch( BOOL BranchBegin,

IDrawingObject * BranchObject,

BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

BranchBegin | \- строить от начала полки,  
---|---  
BranchObject | \- опорный объект.  
  
Метод позволяет добавить ответвление, используя опорный объект.

Подразделы:

(отсутствуют)

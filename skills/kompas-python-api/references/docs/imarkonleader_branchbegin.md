# BranchBegin - Начало ответвления

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IMark ](imark.html) > [IMark - свойства ](imark_props.html) > [Y - Координата точки привязки марки по Y ](imark_y.html) > [Интерфейс IMarkOnLeader ](imarkonleader.html) > [IMarkOnLeader - свойства ](imarkonleader_props.html) |  Scroll [ [ [ ](imarkonleader_branchcount.html "К следующему разделу")](imarkonleader_props.html "На уровень выше")](imarkonleader_arrowtype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imarkonleader.html)

Тип данных: BOOL

Синтаксис Automation:

BranchBegin = iObject.BranchBegin | Получить свойство([* ](1.html))  
---|---  
iObject.BranchBegin = BranchBegin | Установить свойство ([* ](1.html))  
BranchBegin = iObject.GetBranchBegin() | Получить свойство ([**](2.html))  
iObject.SetBranchBegin(BranchBegin) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_BranchBegin(&BranchBegin) | Получить свойство  
---|---  
iObject->put_BranchBegin( BranchBegin) | Установить свойство  
  
Значения свойства:

TRUE | \- от начала полки,  
---|---  
FALSE | \- от конца полки.  
  
Примечание.

Свойство задает признак начала ответвления.

Подразделы:

(отсутствуют)

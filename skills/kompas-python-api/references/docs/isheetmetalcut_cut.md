# Cut - Результат операции

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalCut ](isheetmetalcut.html) > [ISheetMetalCut - свойства ](isheetmetalcut_props.html) |  Scroll [ [ [ ](isheetmetalcut_cuttype.html "К следующему разделу")](isheetmetalcut_props.html "На уровень выше")](isheetmetalcut_body.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetalcut.html)

Тип данных: BOOL

Синтаксис Automation:

Cut = iObject.Cut; | Получить свойство ([* ](1.html))  
---|---  
iObject.Cut = Cut; | Установить свойство ([* ](1.html))  
Cut = iObject.GetCut(); | Получить свойство ([**](2.html))  
iObject.SetCut( Cut ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Cut( &Cut ); | Получить свойство  
---|---  
iObject->put_Cut( Cut ); | Установить свойство  
  
Значения свойства:

TRUE | \- вычитание элемента,  
---|---  
FALSE | \- пересечение элементов.  
  
Примечание.

Позволяет считывать и устанавливать результат операции.

Подразделы:

(отсутствуют)

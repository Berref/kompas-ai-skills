# Faces - Массив граней (SAFEARRAY)

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalLineBend ](isheetmetallinebend.html) > [ISheetMetalLineBend - свойства ](isheetmetallinebend_props.html) |  Scroll [ [ [ ](isheetmetallinebend_internalradius.html "К следующему разделу")](isheetmetallinebend_props.html "На уровень выше")](isheetmetallinebend_dismissalangletype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetallinebend.html)

Тип данных: VARIANT

Синтаксис Automation:

Faces = iObject.Faces; | Получить свойство ([* ](1.html))  
---|---  
iObject.Faces = Faces; | Установить свойство ([* ](1.html))  
Faces = iObject.GetFaces; | Получить свойство ([**](2.html))  
iObject.SetFaces( Faces ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Faces( &Faces ); | Получить свойство  
---|---  
iObject->put_Faces( Faces ); | Установить свойство  
  
Примечание.

Позволяет получать и устанавливать грань или массив граней, участвующих в операции Сгиб по линии. Массив граней возвращается в виде массива SAFEARRAY граней LPDISPATCH (VT_ARRAY | VT_DISPATCH).

Подразделы:

(отсутствуют)

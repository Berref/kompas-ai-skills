# FirstOnSheet - Размещать объект в начале нового листа спецификации

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationObject ](ispecificationobject.html) > [ISpecificationObject - свойства ](ispecificationobject_props.html) |  Scroll [ [ [ ](ispecificationobject_incrementposition.html "К следующему разделу")](ispecificationobject_props.html "На уровень выше")](ispecificationobject_columns.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationobject.html)

Тип данных: BOOL

Синтаксис Automation:

FirstOnSheet = iObject.FirstOnSheet | Получить свойство ([* ](1.html))  
---|---  
iObject.FirstOnSheet = FirstOnSheet | Установить свойство ([* ](1.html))  
FirstOnSheet = iObject.GetFirstOnSheet() | Получить свойство ([**](2.html))  
iObject.SetFirstOnSheet (FirstOnSheet) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_FirstOnSheet (&FirstOnSheet) | Получить свойство  
---|---  
iObject->put_FirstOnSheet (FirstOnSheet) | Установить свойство  
  
Значения свойства:

TRUE | \- объект спецификации разместить в начале новой страницы спецификации,  
---|---  
FALSE | \- объект спецификации разместить после предыдущего.  
  
Примечание:

1\. Свойство доступно только для базового и вспомогательного объекта спецификации.

2\. Изменение этого свойства вступит в силу после вызова метода [ISpecificationObject::Update](ispecificationobject_update.html).

Подразделы:

(отсутствуют)

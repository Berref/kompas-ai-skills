# State - Состояние объекта

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationObject ](ispecificationobject.html) > [ISpecificationObject - свойства ](ispecificationobject_props.html) |  Scroll [ [ [ ](ispecificationobject_subsection.html "К следующему разделу")](ispecificationobject_props.html "На уровень выше")](ispecificationobject_section.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationobject.html)

Тип данных: из перечисления [ksSpecificationObjectStateEnum](ksspecificationobjectstateenum.html)

Синтаксис Automation:

State = iObject.State | Получить свойство ([* ](1.html))  
---|---  
State = iObject.GetState() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_State (&State) | Получить свойство  
---|---  
  
Значения свойства:

ssIndependent | \- объект создан в данном документе,  
---|---  
ssFromInsert | \- объект пришел из вставки другого документа (фрагмента, детали или подсборки),  
ssEdit | \- объект из вставки другого документа, но редактировался в данном документе.  
  
Примечание:

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)

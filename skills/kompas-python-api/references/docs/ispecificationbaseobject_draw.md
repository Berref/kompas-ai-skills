# Draw - Показывать объект

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationBaseObject ](ispecificationbaseobject.html) > [ISpecificationBaseObject - свойства ](ispecificationbaseobject_props.html) |  Scroll [ [ [ ](ispecificationbaseobject_drawposition.html "К следующему разделу")](ispecificationbaseobject_props.html "На уровень выше")](ispecificationbaseobject_documents.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationbaseobject.html)

Тип данных: BOOL

Синтаксис Automation:

Draw = iObject.Draw | Получить свойство ([* ](1.html))  
---|---  
iObject.Draw = Draw | Установить свойство ([* ](1.html))  
Draw = iObject.GetDraw() | Получить свойство ([**](2.html))  
iObject.SetDraw( Draw ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Draw( &Draw ) | Получить свойство  
---|---  
iObject->put_Draw( Draw ) | Установить свойство  
  
Значения свойства:

TRUE | \- объект виден в таблице спецификации в любом режиме работы с ней,  
---|---  
FALSE | \- показывать объект в таблице спецификации не нужно; при этом объект не удаляется (он по-прежнему участвует в расчете номеров позиций).  
  
Примечание:

Свойство позволяет скрыть объект спецификации.

Подразделы:

(отсутствуют)

# UserTextStyle - Стиль текста объектов спецификации пользовательский

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationTuning ](ispecificationtuning.html) > [ISpecificationTuning - свойства ](ispecificationtuning_props.html) |  Scroll [ [ [ ](ispecificationtuning_methods.html "К следующему разделу")](ispecificationtuning_props.html "На уровень выше")](ispecificationtuning_useadditionalblocks.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationtuning.html)

Тип данных: BOOL

Синтаксис Automation:

UserTextStyle = iObject.UserTextStyle | Получить свойство ([* ](1.html))  
---|---  
iObject.UserTextStyle = UserTextStyle | Установить свойство ([* ](1.html))  
UserTextStyle = iObject.GetUserTextStyle() | Получить свойство ([**](2.html))  
iObject.SetUserTextStyle (UserTextStyle) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_UserTextStyle (&UserTextStyle) | Получить свойство  
---|---  
iObject->put_UserTextStyle (UserTextStyle) | Установить свойство  
  
Значения свойства:

TRUE | \- шрифт текстовой части объектов спецификации задается свойством [ObjectTextStyle](ispecificationtuning_objecttextstyle.html),  
---|---  
FALSE | \- шрифт текстовой части объектов спецификации будет таким, каким он был установлен по умолчанию в таблице спецификации.  
  
Примечание:

Позволяет определить, какой шрифт будет использоваться для отображения текстовой части объектов спецификации.

Подразделы:

(отсутствуют)

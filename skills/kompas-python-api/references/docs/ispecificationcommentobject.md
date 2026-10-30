# Интерфейс ISpecificationCommentObject

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) |  Scroll [ [ [ ](ispecificationcommentobject_props.html "К следующему разделу")](spec_work.html "На уровень выше")](ispecificationcolumnstyle_valuetype.html "К предыдущему разделу")  
---|---  
  
Интерфейс вспомогательного объекта спецификации.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[ISpecificationObject](ispecificationobject.html)

[ISpecificationCommentObject](ispecificationcommentobject.html)

Описание:

Интерфейс позволяет получить и изменить параметры вспомогательного объекта спецификации. В отличие от базового для вспомогательного объекта не предусмотрены сервисные функции, выполнение которых обеспечивает спецификация. Вспомогательные объекты не сортируются автоматически и т.д. Вспомогательные объекты рекомендуется использовать для выполнения таких приемов оформления спецификации, которые не могут быть обеспечены вводом базовых объектов. Например, при помощи вспомогательного объекта спецификации можно ввести произвольный текст (комментарий) в таблицу спецификации или создать пустую строку в середине раздела.

Примечание:

1\. После изменения параметров объекта спецификации требуется вызвать метод [ISpecificationObject::Update](ispecificationobject_update.html).

2\. Данный интерфейс можно получить у коллекции базовых объектов спецификации [ISpecificationCommentObjects](ispecificationcommentobjects.html).

Подразделы:

[ISpecificationCommentObject - свойства ](ispecificationcommentobject_props.html)

[ISpecificationCommentObject - методы ](ispecificationcommentobject_methods.html)

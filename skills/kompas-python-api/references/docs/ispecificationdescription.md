# Интерфейс ISpecificationDescription

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) |  Scroll [ [ [ ](ispecificationdescription_props.html "К следующему разделу")](spec_work.html "На уровень выше")](ispecificationcommentobject_setsection.html "К предыдущему разделу")  
---|---  
  
Интерфейс описания спецификации у документа.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[ISpecificationDescription](ispecificationdescription.html)

Описание:

Описание спецификации включает в себя имя файла спецификации, подключенной к графическому документу и стиль этой спецификации.

Для фрагмента и детали описание спецификации содержит только стиль спецификации. Это связано с тем, что фрагмент и деталь непосредственно к спецификации не подключаются, но в них можно создавать объекты спецификации для передачи в чертежи и сборки.

Примечание:

Установка свойств доступна только для графических документов и документов-моделей. Для документа спецификации свойства интерфейса работают в режиме "только для чтения". После изменения параметров оформления нужно вызвать метод [Update](ispecificationdescription_update.html), чтобы новые данные вступили в силу.

Данный интерфейс можно получить у коллекции описаний спецификации [ISpecificationDescriptions](ispecificationdescriptions.html).

Подразделы:

[ISpecificationDescription - свойства ](ispecificationdescription_props.html)

[ISpecificationDescription - методы ](ispecificationdescription_methods.html)

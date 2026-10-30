# Интерфейс IAttachedDocuments

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) |  Scroll [ [ [ ](iattacheddocuments_props.html "К следующему разделу")](spec_work.html "На уровень выше")](iadditionalblocktunings_item.html "К предыдущему разделу")  
---|---  
  
Интерфейс коллекции документов, присоединенных к объекту спецификации.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IKompasCollection](ikompascollection.html)

[IAttachedDocuments](iattacheddocuments.html)

Описание:

Объект спецификации можно связать с документами КОМПАС-3D. Эта связь является двусторонней и ассоциативной и позволяет передавать данные об объекте спецификации в подключенный документ или наоборот, данные из документа в соответствующий ему объект спецификации. Если к объекту спецификации подключено несколько документов, то в объект передаются данные из первого подключенного документа. Если отредактировать подключенную к объекту модель или данные в основной надписи подключенного документа, а также изменить его формат, то при сохранении этого документа будет выдан запрос на подтверждение передачи данных в спецификацию. После изменения наименования или обозначения объекта в документе-спецификации новые данные могут быть переданы в основную надпись подключенного документа.

Примечание:

1\. Управляет массивом интерфейсов [IAttachedDocument](iattacheddocument.html).

2\. Данный интерфейс можно получить у интерфейса объекта спецификации [ISpecificationObject](ispecificationobject.html) с помощью свойства [ISpecificationObject::AttachedDocuments](ispecificationobject_attacheddocuments.html).

Подразделы:

[IAttachedDocuments - свойства ](iattacheddocuments_props.html)

[IAttachedDocuments - методы ](iattacheddocuments_methods.html)

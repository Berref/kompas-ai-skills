# Delete - Удалить ссылку на документ

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс IAttachedDocument ](iattacheddocument.html) > [IAttachedDocument - методы ](iattacheddocument_methods.html) |  Scroll [ [ [ ](ibilletsobjectsmanager.html "К следующему разделу")](iattacheddocument_methods.html "На уровень выше")](iattacheddocument_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iattacheddocuments.html)

Синтаксис Automation:

BOOL Delete();

Синтаксис COM:

HRESULT Delete( [out, retval] BOOL* Result );

Примечание:

1\. Метод позволяет удалить ссылку на документ.

2\. После удаления нужных документов вызвать метод [ISpecificationObject::Update](ispecificationobject_update.html).

Подразделы:

(отсутствуют)

# Update - Обновить данные

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationObject ](ispecificationobject.html) > [ISpecificationObject - методы ](ispecificationobject_methods.html) |  Scroll [ [ [ ](ispecificationobjectcreateparam.html "К следующему разделу")](ispecificationobject_methods.html "На уровень выше")](ispecificationobject_edit.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationobject.html)

Синтаксис Automation:

BOOL Update();

Синтаксис COM:

HRESULT Update ([out, retval] BOOL* Result);

Примечание:

После изменения параметров объекта спецификации требуется вызвать данный метод, чтобы новые данные попали в модельный объект спецификации. Если объект спецификации еще не создан, метод Update создает объект спецификации в документе.

Для ускорения работы функции при массовом изменении спецификации рекомендуется воспользоваться методом [ISpecificationDescription::NeedRebuild](ispecificationdescription_needrebuild.html).

Подразделы:

(отсутствуют)

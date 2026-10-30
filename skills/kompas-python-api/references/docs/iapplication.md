# Интерфейс IApplication

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) |  Scroll [ [ [ ](iapplication_props.html "К следующему разделу")](ap1782828.html "На уровень выше")](ikompascollection_count.html "К предыдущему разделу")  
---|---  
  
Интерфейс приложения КОМПАС-3D.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IApplication](iapplication.html)

[IAttrTypeMng](iattrtypemng.html)

[IPropertyMng](ipropertymng.html)

Примечание:

1\. Приложение КОМПАС-3D регистрируется с ProgID «KOMPAS.Application.7».

2\. После запуска приложения из-под внешнего контроллера оно работает в слепом режиме. Чтобы оно стало видимым, нужно установить свойству [IApplication::Visible](iapplication_visible.html) значение TRUE.

3\. Данный интерфейс приложения можно получить у любого объекта с помощью свойства [IKompasAPIObject::Application](ikompasapiobject_application.html).

4\. Интерфейс приложения может быть создан следующими способами:

•в С с помощью функций HINSTANCE LoadLibrary(LibFileName), GetProcAddress, CreateKompasApplication(), пример создания интерфейса реализован в функции GetNewKompasAPI() - SDK\VisualC: Gayka1, Step12, Cube;

•в Delphi с помощью функции CreateKompasApplication, пример создания интерфейса реализован в функции GetNewKompasAPI() - SDK\Pascal\Delphi: Gayka1, Step12, Cube;

•в VBasic с помощью функции ksGetApplication7, пример создания интерфейса реализован в SDK\Basic: Gayka1, events.

5\. Посредством вызова метода [IUnknown::QueryInterface (const GUID far& iid, void** pif)](recomendation.html) у данного интерфейса можно получить дополнительные интерфейсы [IAttrTypeMng,](iattrtypemng.html)[IPropertyMng](ipropertymng.html) и [IApplicationLicenseManager](iapplicationlicensemanager.html).

Подразделы:

[IApplication - свойства ](iapplication_props.html)

[IApplication - методы ](iapplication_methods.html)

[IApplication - события ](iapplication_events.html)

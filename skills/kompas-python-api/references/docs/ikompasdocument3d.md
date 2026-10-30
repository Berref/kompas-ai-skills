# Интерфейс IKompasDocument3D

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument ](ikompasdocument.html) > [IKompasDocument - методы ](ikompasdocument_methods.html) |  Scroll [ [ [ ](ikompasdocument3d_props.html "К следующему разделу")](ikompasdocument_methods.html "На уровень выше")](idrawingdocument_technicaldemand.html "К предыдущему разделу")  
---|---  
  
Базовый класс документов-моделей КОМПАС (скрытый).

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IKompasDocument](ikompasdocument.html)

[IKompasDocument3D](ikompasdocument3d.html)

[IExternalTessellationManager](iexternaltessellationmanager.html)

[ISelectionManager](iselectionmanager.html)

[IChooseManager](ichoosemanager.html)

[Интерфейс событий...](ksplmobjectnotify.html)

Синтаксис Automation:

IKompasDocument3D document3D (application.GetActiveDocument());

Синтаксис COM:

pApplication->get_ActiveDocument( &document3D );

Примечание:

1\. Данный интерфейс является базовым для интерфейсов документов-моделей КОМПАС API – детали [IPartDocument](ipartdocument.html) и сборки [IAssemblyDocument](iassemblydocument.html).

2\. Интерфейс можно получить у интерфейса приложения [IApplication](iapplication.html) с помощью свойства [IApplication::ActiveDocument](iapplication_activedocument.html) или свойства [IApplication::Documents](iapplication_documents.html).

3\. У данного интерфейса посредством вызова метода [IUnknown::QueryInterface (const GUID far& IID, void** pif)](recomendation.html) можно получить дополнительные интерфейсы:

•[IEmbodimentsManager](iembodimentsmanager.html)

•[IExternalTessellationManager](iexternaltessellationmanager.html)

•[ISelectionManager](iselectionmanager.html)

•[IChooseManager](ichoosemanager.html)

Подразделы:

[IKompasDocument3D - свойства ](ikompasdocument3d_props.html)

[IKompasDocument3D - методы ](ikompasdocument3d_methods.html)

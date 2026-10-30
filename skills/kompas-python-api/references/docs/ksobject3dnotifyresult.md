# Интерфейс результатов редактирования объекта (Интерфейсы ksObject3DNotifyResult, IObject3DNotifyResult)

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект Дерева построения (Интерфейсы ksFeature, IFeature) ](ksfeature.html) |  Scroll [ [ [ ](ksobject3dnotifyresult_methods.html "К следующему разделу")](ksfeature.html "На уровень выше")](kscolorparam_clear.html "К предыдущему разделу")  
---|---  
  
Интерфейс результатов редактирования объекта документа-модели.

ksObject3DNotifyResult | \- интерфейс Automation  
---|---  
IObject3DNotifyResult | \- интерфейс COM  
  
В Automation получить интерфейс результата можно получить при помощи метода [ksPart::GetObject3DNotifyResult](kspart_getobject3dnotifyresult.html).

В COM получить интерфейс результата можно при помощи метода [IPart::GetObject3DNotifyResult](kspart_getobject3dnotifyresult.html).

Примечание:

В процессе обработки события[ Object3DNotifyEnum](ksobject3dnotifyenum.html) можно получить информацию о редактировании объекта.

Подразделы:

[IObject3DNotifyResult - методы ](ksobject3dnotifyresult_methods.html)

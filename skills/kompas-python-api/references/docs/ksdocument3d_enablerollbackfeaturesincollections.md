# enableRollBackFeaturesInCollections - Выдавать в коллекциях объекты, исключенные указателем в дереве

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - свойства ](ksdocument3d_properties.html) |  Scroll [ [ [ ](ksdocument3d_filename.html "К следующему разделу")](ksdocument3d_properties.html "На уровень выше")](ksdocument3d_drawmode.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Тип данных: BOOL

Синтаксис Automation:

enable = iDocument3D.enableRollBackFeaturesInCollections | Получить свойство ([* ](1.html))  
---|---  
iDocument3D.enableRollBackFeaturesInCollections = enable | Установить свойство ([* ](1.html))  
enable = document.GetenableRollBackFeaturesInCollections() | Получить свойство([**](2.html))  
document.SetenableRollBackFeaturesInCollections(enable) | Установить свойство([**](2.html))  
  
Примечание:

По умолчанию объекты, исключенные с помощью указателя (зеленая полоска) дерева, не выдаются. Свойство используется для получения исключенных объектов дерева, которые можно использовать для изменения положения указателя в дереве.

См. функции [ksDocument3D::GetRollBackFeature](ksdocument3d_getrollbackfeature.html) и [ksDocument3D::SetRollBackFeature](ksdocument3d_setrollbackfeature.html).

Подразделы:

(отсутствуют)

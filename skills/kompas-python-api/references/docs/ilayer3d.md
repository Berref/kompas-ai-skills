# Интерфейс ILayer3D

[API интерфейсов. Версия 7](applicate.html) > [Сервисные функции ](service.html) > [Слои ](cu1735361.html) |  Scroll [ [ [ ](ilayer3d_props.html "К следующему разделу")](cu1735361.html "На уровень выше")](ilayergroups3d_add.html "К предыдущему разделу")  
---|---  
  
Интерфейс cлоя в 3D.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[ILayer3D](ilayer3d.html)

Интерфейс можно получить у коллекции слоев 3D с помощью свойства [ILayers3D::Layer3D](ilayers3d_layer3d.html) и метода [ILayers3D::Add](ilayers3d_add.html).

Имеет дополнительный интерфейс [IColorParam7](icolorparam7.html), который можно получить с помощью метода [IUnknown::QueryInterface](recomendation.html).

Примечание:

Чтобы новые параметры интерфейса [IColorParam7](icolorparam7.html) слоя [ILayer3D](ilayer3d.html) обновились у объектов модели, нужно вызвать метод [IDocument3DManager::Update](idocument3dmanager_update.html).

Подразделы:

[ILayer3D - свойства ](ilayer3d_props.html)

[ILayer3D - методы ](ilayer3d_methods.html)

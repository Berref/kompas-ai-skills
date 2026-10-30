# FeatureType - Тип объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IFeature7 ](ifeature7.html) > [IFeature7 - свойства ](ifeature7_props.html) |  Scroll [ [ [ ](ifeature7_label.html "К следующему разделу")](ifeature7_props.html "На уровень выше")](ifeature7_isrollbacked.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ifeature7.html)

Тип данных: из перечисления [ksObj3dTypeEnum](obj3dtype.html)

Синтаксис Automation:

FeatureType = iObject.FeatureType | Получить свойство ([* ](1.html))  
---|---  
FeatureType = iObject.GetFeatureType() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_FeatureType(&FeatureType) | Получить свойство  
---|---  
  
Возвращаемое значение:

| \- тип объектов из перечисления [ksObj3dTypeEnum](obj3dtype.html).  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. Тип возвращаемого объекта может принимать значения:

o3d_part | \- деталь,  
---|---  
o3d_entity | \- объект,  
o3d_mateConstraint | \- сопряжение.  
  
Подразделы:

(отсутствуют)

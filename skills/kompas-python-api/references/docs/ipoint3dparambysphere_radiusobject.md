# RadiusObject - Объект радиуса

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Точки ](bc2284065.html) > [Интерфейс IPoint3DParamBySphere ](ipoint3dparambysphere.html) > [IPoint3DParamBySphere - свойства ](ipoint3dparambysphere_props.html) |  Scroll [ [ [ ](bc2287727.html "К следующему разделу")](ipoint3dparambysphere_props.html "На уровень выше")](ipoint3dparambysphere_r.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipoint3dparambysphere.html)

Тип данных: указатель на интерфейс объекта [IModelObject](imodelobject.html)

Синтаксис Automation:

RadiusObject = Object.RadiusObject | Получить свойство ([* ](1.html))  
---|---  
Object.RadiusObject = RadiusObject | Установить свойство ([* ](1.html))  
RadiusObject = Object.GetRadiusObject() | Получить свойство ([**](2.html))  
Object.SetRadiusObject( RadiusObject ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_RadiusObject( &RadiusObject ) | Получить свойство  
---|---  
Object.put_RadiusObject( RadiusObject ) | Установить свойство  
  
Свойство позволяет устанавливать и получать объект, задающий радиус. Таким объектом может являться ребро или контур в эскизе, имеющий форму окружности или дуги окружности; кривая - окружность или дуга; цилиндрическая или сферическая грань.

Примечание:

Если задан объект, определяющий радиус, координата R недоступна для изменения.

Подразделы:

(отсутствуют)

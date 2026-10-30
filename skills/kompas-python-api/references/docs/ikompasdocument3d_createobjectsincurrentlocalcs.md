# CreateObjectsInCurrentLocalCS - Создавать новые объекты в текущей ЛСК

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument ](ikompasdocument.html) > [IKompasDocument - методы ](ikompasdocument_methods.html) > [Интерфейс IKompasDocument3D ](ikompasdocument3d.html) > [IKompasDocument3D - свойства ](ikompasdocument3d_props.html) |  Scroll [ [ [ ](ikompasdocument3d_drawmode.html "К следующему разделу")](ikompasdocument3d_props.html "На уровень выше")](ikompasdocument3d_choosemanager.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument3d.html)

Тип данных: BOOL

Синтаксис Automation:

CreateObjectsInCurrentLocalCS = Object.CreateObjectsInCurrentLocalCS | Получить свойство ([* ](1.html))  
---|---  
Object.CreateObjectsInCurrentLocalCS = CreateObjectsInCurrentLocalCS | Установить свойство ([* ](1.html))  
CreateObjectsInCurrentLocalCS = Object.GetCreateObjectsInCurrentLocalCS() | Получить свойство ([**](2.html))  
Object.SetCreateObjectsInCurrentLocalCS( CreateObjectsInCurrentLocalCS ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_CreateObjectsInCurrentLocalCS( &CreateObjectsInCurrentLocalCS ) | Получить свойство  
---|---  
Object.put_CreateObjectsInCurrentLocalCS( CreateObjectsInCurrentLocalCS ) | Установить свойство  
  
Примечание:

Свойство позволяет включить режим создания объектов модели в текущей системе координат. Для правильной работы библиотек нужно включить режим, создать нужные объекты и выключить режим.

Если флаг включен, то 3D точка, ломаная, сплайн, эскиз, импортированная поверхность, операция без истории, деталь заготовка через API будут создаваться в текущей локальной системе координат.

Параметры создания в локальной системе координат зависят от настроек системы.

См. также: [ISystemSettings::ModelLocalCSCreateInAbsoluteCS](isystemsettings_modellocalcscreateinabsolutecs.html) и [ISystemSettings::ModelLocalCSSetActive](isystemsettings_modellocalcssetactive.html).

Подразделы:

(отсутствуют)

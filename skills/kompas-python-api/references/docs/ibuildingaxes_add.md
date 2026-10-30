# Add - Создать ось

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IBuildingAxes ](ibuildingaxes.html) > [IBuildingAxes - методы ](ibuildingaxes_methods.html) |  Scroll [ [ [ ](imarks.html "К следующему разделу")](ibuildingaxes_methods.html "На уровень выше")](ibuildingaxes_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibuildingaxes.html)

Синтаксис Automation:

LPDISPATH Add( DrawingObjectTypeEnum type );

Синтаксис COM:

HRESULT Add( DrawingObjectTypeEnum type, IBuildingAxis** Result);

Входные параметры:

| type - тип объекта из перечисления [DrawingObjectTypeEnum](objtypes.html).  
---|---  
  
Возможные значения type:

ksDrStraightAxis | 56 | [IStraightAxis](istraightaxis.html) Прямая ось,  
---|---|---  
ksDrCircleAxis | 58 | [ICircleAxis](icircleaxis.html) Круговая ось,  
ksDrArcAxis | 59 | [IArcAxis](iarcaxis.html) Дуговая ось.  
  
Возвращаемое значение:

Result | \- Указатель на базовый интерфейс для строительных осей [IBuildingAxis](ibuildingaxis.html).  
---|---  
  
Примечание:

Метод позволяет создать новый интерфейс строительной оси. После получения нового интерфейса нужно задать параметры марки и вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

(отсутствуют)

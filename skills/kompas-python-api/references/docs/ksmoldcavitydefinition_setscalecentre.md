# SetScaleCentre - Установить вершину, относительно которой выполняется масштабирование

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы поверхностей ](nt_surface.html) > [Интерфейс операции вычитания компонентов (ksMoldCavityDefinition, IMoldCavityDefinition) ](ksmoldcavitydefinition.html) > [ksMoldCavityDefinition - методы ](ksmoldcavitydefinition_methods.html) |  Scroll [ [ [ ](ksmacro3ddefinition.html "К следующему разделу")](ksmoldcavitydefinition_methods.html "На уровень выше")](ksmoldcavitydefinition_partarray.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmoldcavitydefinition.html)

Синтаксис Automation:

VARIANT_BOOL SetScaleCentre( LPDISPATCH vert );

Синтаксис COM:

BOOL SetScaleCentre( LPENTITY vert );

Входные параметры:

vert | \- Указатель на интерфейс коллекции компонентов [ksEntity](ksentity.html) или [IEntity](ksentity.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи  
  
Примечания.

В качестве вершины могут использоваться характерные точки графических объектов в эскизах (например, конец отрезка, центр окружности и т.п.) или начала координат. Если вершина не указана, то используется точка, являющаяся центром масс деталей.

Подразделы:

(отсутствуют)

# SetFaceEnd - Установить грань, до которой строится резьба

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы дополнительных элементов ](int_additional.html) > [Условное изображение резьбы (Интерфейсы ksThreadDefinition, IThreadDefinition) ](ksthreaddefinition.html) > [IThreadDefinition - методы ](ksthreaddefinition_methods.html) |  Scroll [ [ [ ](ksloopcollection.html "К следующему разделу")](ksthreaddefinition_methods.html "На уровень выше")](ksthreaddefinition_setfacebegin.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksthreaddefinition.html)

Синтаксис Automation:

BOOL SetFaceEnd (LPDISPATCH face);

Синтаксис COM:

BOOL SetFaceEnd (LPENTITY face);

Входной параметр:

face | \- указатель на интерфейс объекта [ksEntity](ksentity.html) или [IEntity](ksentity.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Начальная и конечная грань - любые грани, ограничивающие резьбу. Начальная и конечная грань применяются для определения длины резьбы при включенной опции автоматического определения длины. Кроме того, начальная грань указывает, откуда откладывается резьба.

Подразделы:

(отсутствуют)

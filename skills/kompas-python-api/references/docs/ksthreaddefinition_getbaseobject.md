# GetBaseObject - Получить указатель на интерфейс базового объекта (ребра или грани), по которому строится резьба

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы дополнительных элементов ](int_additional.html) > [Условное изображение резьбы (Интерфейсы ksThreadDefinition, IThreadDefinition) ](ksthreaddefinition.html) > [IThreadDefinition - методы ](ksthreaddefinition_methods.html) |  Scroll [ [ [ ](ksthreaddefinition_getfacebegin.html "К следующему разделу")](ksthreaddefinition_methods.html "На уровень выше")](ksthreaddefinition_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksthreaddefinition.html)

Синтаксис Automation:

LPDISPATCH GetBaseObject();

Синтаксис COM:

LPENTITY GetBaseObject();

Возвращаемое значение:

| \- указатель на интерфейс [ksEntity](ksentity.html) или [IEntity](ksentity.html).  
---|---  
  
Примечание:

1\. Базовый объект может быть как ребром, так и гранью. Тип базового объекта определяется методами интерфейсов [ksEntity](ksentity.html) или [IEntity](ksentity.html).

2\. Если базовым объектом является ребро, то базовая грань определяется автоматически. При этом задание начальной и конечной грани не обязательно, хотя возможно. Если базовым объектом является грань, то указывать начальную и конечную грани необходимо. Базовая грань должна быть цилиндрической либо конической, начальная и конечная грань - любые грани, ограничивающие резьбу. Базовое ребро должно быть окружностью, принадлежащей цилиндру.

Подразделы:

(отсутствуют)

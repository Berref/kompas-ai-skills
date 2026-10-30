# faceValue - Направление построения резьбы

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы дополнительных элементов ](int_additional.html) > [Условное изображение резьбы (Интерфейсы ksThreadDefinition, IThreadDefinition) ](ksthreaddefinition.html) > [IThreadDefinition - свойства ](ksthreaddefinition_props.html) |  Scroll [ [ [ ](ksthreaddefinition_length.html "К следующему разделу")](ksthreaddefinition_props.html "На уровень выше")](ksthreaddefinition_dr.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksthreaddefinition.html)

Тип данных: BOOL

Синтаксис Automation:

faceValue = iThreadDefinition.faceValue | Получить свойство ([* ](1.html))  
---|---  
iThreadDefinition.faceValue = faceValue | Установить свойство ([* ](1.html))  
iThreadDefinition.GetFaceValue() | Получить свойство ([**](2.html))  
iThreadDefinition.SetFaceValue(faceValue) | Установить свойство ([**](2.html))  
  
Примечание:

Если базовое ребро изменено, то при вызове методов Update или Create автоматически будет произведена проверка направления резьбы. В случае ошибки направление изменится.

Подразделы:

(отсутствуют)

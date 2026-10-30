# allLength - Полная длина

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы дополнительных элементов ](int_additional.html) > [Условное изображение резьбы (Интерфейсы ksThreadDefinition, IThreadDefinition) ](ksthreaddefinition.html) > [IThreadDefinition - свойства ](ksthreaddefinition_props.html) |  Scroll [ [ [ ](ksthreaddefinition_autodefindr.html "К следующему разделу")](ksthreaddefinition_props.html "На уровень выше")](ksthreaddefinition_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksthreaddefinition.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- длина резьбы [length](ksthreaddefinition_length.html) не зависит от значения указанного пользователем,  
---|---  
FALSE | \- длина резьбы задается пользователем.  
  
Синтаксис Automation:

allLength = iThreadDefinition.allLength | Получить свойство ([* ](1.html))  
---|---  
iThreadDefinition.allLength = allLength | Установить свойство ([* ](1.html))  
allLength = iThreadDefinition.GetAllLength() | Получить свойство ([**](2.html))  
iThreadDefinition.SetAllLength(allLength) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)

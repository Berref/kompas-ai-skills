# Exemplar - Получить экземпляр по индексу (или индексам)

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Массивы ](bc3321786.html) > [Интерфейс IFeaturePattern ](ifeaturepattern.html) > [IFeaturePattern - свойства ](ifeaturepattern_props.html) |  Scroll [ [ [ ](ifeaturepattern_geometrypattern.html "К следующему разделу")](ifeaturepattern_props.html "На уровень выше")](ifeaturepattern_basepointtype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ifeaturepattern.html)

Тип данных: Указатель на интерфейс [IModelObject](imodelobject.html)

Синтаксис Automation:

Exemplar = Object.Exemplar( index1, index2 ) | Получить свойство ([* ](1.html))  
---|---  
Exemplar = Object.GetExemplar( index1, index2 ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Exemplar( index1, index2, &Exemplar ) | Получить свойство  
---|---  
  
Входные параметры

index1, index2 - индекс экземпляра

Примечание:

Свойство доступно только для чтения.

Значения индексов начинаются с 1.

В массиве по кривой используется один индекс (первый).

Подразделы:

(отсутствуют)

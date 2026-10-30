# InstanceDeletedIndexes - Список удаленных экземпляров массива

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Массивы ](bc3321786.html) > [Интерфейс IFeaturePattern ](ifeaturepattern.html) > [IFeaturePattern - свойства ](ifeaturepattern_props.html) |  Scroll [ [ [ ](ifeaturepattern_methods.html "К следующему разделу")](ifeaturepattern_props.html "На уровень выше")](ifeaturepattern_initialobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ifeaturepattern.html)

Тип данных: VARIANT

Синтаксис Automation:

InstanceDeletedIndexes = Object.InstanceDeletedIndexes | Получить свойство ([* ](1.html))  
---|---  
Object.InstanceDeletedIndexes = InstanceDeletedIndexes | Установить свойство ([* ](1.html))  
InstanceDeletedIndexes = Object.GetInstanceDeletedIndexes() | Получить свойство ([**](2.html))  
Object.SetInstanceDeletedIndexes( InstanceDeletedIndexes ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_InstanceDeletedIndexes( &InstanceDeletedIndexes ) | Получить свойство  
---|---  
Object.put_InstanceDeletedIndexes( InstanceDeletedIndexes ) | Установить свойство  
  
Примечания:

Возвращается массив SafeArray VT_ARRAY | VT_I4.

Свойства применяется для получения информации об удаленных копиях, а также управления составом удаленных копий.

Информация об удаленной копии выдается в виде индексов копии в узоре копирования.

В общем случае это два индекса по ортогональным осям в плоскости узора.

Для копий по кривой используется один индекс (первый).

Значения индексов начинаются с 1.

Подразделы:

(отсутствуют)

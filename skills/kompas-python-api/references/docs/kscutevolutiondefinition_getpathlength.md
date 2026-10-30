# GetPathLength - Получить длину результирующей кривой траектории

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Вырезанный кинематический элемент (Интерфейс ksCutEvolutionDefinition, ICutEvolutionDefinition) ](kscutevolutiondefinition.html) > [ICutEvolutionDefinition - методы ](kscutevolutiondefinition_methods.html) |  Scroll [ [ [ ](kscutevolutiondefinition_getsketch.html "К следующему разделу")](kscutevolutiondefinition_methods.html "На уровень выше")](kscutevolutiondefinition_chooseparts.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscutevolutiondefinition.html)

Синтаксис Automation:

double GetPathLength (unsigned long bitVector);

Синтаксис COM:

double GetPathLength(unsigned long bitVector);

Входные параметры:

bitVector | \- единицы измерения в интервале [ST_MIX_MM..ST_MIX_M].  
---|---  
  
Возвращаемое значение:

длина результирующей кривой траектории | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечания:

Метод работает только на уже построенной операции.

Подразделы:

(отсутствуют)

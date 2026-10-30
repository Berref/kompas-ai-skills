# ksInsertFragmentEx - Вставить фрагмент в документ

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Фрагмент (Интерфейс ksFragment) ](ksfragment.html) > [ksFragment - методы ](ksfragment_methods.html) |  Scroll [ [ [ ](ksfragment_kslocalfragmentdefinition.html "К следующему разделу")](ksfragment_methods.html "На уровень выше")](ksfragment_ksinsertfragment.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksfragment.html)

Аналог данного метода при использовании API экспортных функций - [ksInsertFragmentEx](ksinsertfragmentex.html).

Синтаксис Automation:

long ksInsertFragmentEx (long p,

BOOL curentLayer,

LPDISPATCH par,

BOOL scaleProjLinesSize);

Входные параметры:

p | \- указатель на фрагмент,  
---|---  
curentLayer | \- тип размещения объектов фрагмента по слоям: 0 - на "свои" слои, 1- на текущий слой,  
par | \- указатель на интерфейс [ksPlacementParam](ksplacementparam.html),  
scaleProjLinesSize | \- признак масштабирования длины выносных линий размеров: TRUE - выносные линии масштабируются, FALSE - выносные линии не масштабируются.  
  
Возвращаемое значение:

указатель на вставку фрагмента | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)

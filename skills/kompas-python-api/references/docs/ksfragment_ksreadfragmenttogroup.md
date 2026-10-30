# ksReadFragmentToGroup - Вставить фрагмент россыпью во временную группу

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Фрагмент (Интерфейс ksFragment) ](ksfragment.html) > [ksFragment - методы ](ksfragment_methods.html) |  Scroll [ [ [ ](ksfragment_ksreadfragmenttogroupex.html "К следующему разделу")](ksfragment_methods.html "На уровень выше")](ksfragment_ksreadfragment.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksfragment.html)

Аналог данного метода при использовании API экспортных функций - [ksReadFragmentToGroup](ksreadfragmenttogroup.html).

Замечание:

Данный метод устарел. Рекомендуется использовать вместо него метод [ksReadFragmentToGroupEx](ksfragment_ksreadfragmenttogroupex.html).

Синтаксис Automation:

long ksReadFragmentToGroup (LPCTSTR fileName,

BOOL curentLayer,

LPDISPATCH par);

Входные параметры:

fileName | \- имя фрагмента,  
---|---  
curentLayer | \- тип размещения объектов фрагмента по слоям: 0 - на "свои" слои, 1- на текущий слой,  
par | \- указатель на интерфейс [ksPlacementParam](ksplacementparam.html).  
  
Возвращаемое значение:

указатель на временную группу | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Допускается задание имени файла следующего вида: "c:\gr\lib1.lfr|детали|литье|фланец",

где

c:\gr\lib1.lfr - имя файла библиотеки фрагментов,

|детали|литье| - разделы, подразделы внутри библиотеки фрагментов,

фланец - имя фрагмента.

В этом случае фрагмент берется из библиотеки фрагментов.

Подразделы:

(отсутствуют)

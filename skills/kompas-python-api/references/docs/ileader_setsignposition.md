# SetSignPosition - Установить координаты точки привязки знака на линии выноски

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Элементы обозначений ](bb2348381.html) > [Интерфейс ILeader ](ileader.html) > [ILeader - методы](ileader_methods.html) |  Scroll [ [ [ ](ipositionleader.html "К следующему разделу")](ileader_methods.html "На уровень выше")](ileader_getsignposition.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ileader.html)

Синтаксис Automation:

BOOL SetSignPosition( long BranchIndex, double X, double Y );

Синтаксис COM:

HRESULT SetSignPosition( long BranchIndex, double X, double Y, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

BranchIndex | \- индекс, с которым добавляется ответвление,  
---|---  
X, Y | \- координаты точки привязки.  
  
Версия КОМПАС v22

Подразделы:

(отсутствуют)

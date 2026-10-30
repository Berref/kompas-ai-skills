# AddTab - Добавить вкладку

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [Интерфейс IFrameTreesManager ](iframetreesmanager.html) > [IFrameTreesManager - методы ](iframetreesmanager_methods.html) |  Scroll [ [ [ ](iframetreesmanager_addtabex.html "К следующему разделу")](iframetreesmanager_methods.html "На уровень выше")](iframetreesmanager_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iframetreesmanager.html)

Синтаксис Automation:

LPDISPATCH AddTab( BSTR tabCaption, BSTR ocxProgID );

Синтаксис COM:

HRESULT AddTab( BSTR tabCaption, BSTR ocxProgID, IDispatch ** PVal );

Входные параметры:

tabCaption | \- заголовок для новой закладки,  
---|---  
ocxProgID | \- ProgID - ActiveX элемента (ActiveX дерева ); Например, «VCTree.VCTreeCtrl.1» - для создания дерева, из примеров SDK. см SDK\lib\VCTree.ocx, проект SDK\OCX\VCTree. Пример использования SDK\C++\Visualc\TestVCTree.  
  
Возвращаемое значение:

| \- Указатель на интерфейс созданного ActiveX элемента.  
---|---  
  
Подразделы:

(отсутствуют)

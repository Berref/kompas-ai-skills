////////////////////////////////////////////////////////////////////////////////
//
// IPropertyTree_Sample.cpp - Библиотека на Visual C++
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <afxdllx.h>
#include <vector>
#include "IPropertyTree_Sample.h"
#include "PropManager\CPropMen.h"
#include "aPropUserEvent.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


//-------------------------------------------------------------------------------
// Специальная структура используемая в течении инициализации DLL
// ---
static AFX_EXTENSION_MODULE IPropertyTree_SampleDLL = { NULL, NULL };
HINSTANCE g_hInstance = NULL;
IApplicationPtr newKompasAPI(NULL);

void OnProcessDetach();                            // Отключение библиотеки

template <class T>
void FillDispArray(const _variant_t& var, PArray<T>& dispArr)
{
  if (var.vt == VT_DISPATCH)
  {
    dispArr.Add(new T(var.pdispVal));
  }
  else if (var.vt == (VT_ARRAY | VT_DISPATCH))
  {
    LPDISPATCH HUGEP* pvar = nullptr;
    ::SafeArrayAccessData(var.parray, (void HUGEP * FAR*) & pvar);
    if (pvar)
    {
      // Добавляем комментарии в коллекцию
      for (long i = 0, count = var.parray->rgsabound[0].cElements; i < count; ++i)
        dispArr.Add(new T(pvar[i]));

      ::SafeArrayUnaccessData(var.parray);
    }
  }
}

//-------------------------------------------------------------------------------
// Стандартная точка входа
// Инициализация и завершение DLL
// ---
extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
  g_hInstance = hInstance;

  if (dwReason == DLL_PROCESS_ATTACH)
  {
    TRACE0("IPropertyTree_Sample.AWX Initializing!\n");

    AfxInitExtensionModule(IPropertyTree_SampleDLL, hInstance);

    new CDynLinkLibrary(IPropertyTree_SampleDLL);
  }
  else if (dwReason == DLL_PROCESS_DETACH)
  {
    TRACE0("IPropertyTree_Sample.AWX Terminating!\n");
    OnProcessDetach();
    AfxTermExtensionModule(IPropertyTree_SampleDLL);
  }
  return 1;   // ok
}


//-------------------------------------------------------------------------------
// Получить доступ к новому API
// ---
void GetNewKompasAPI()
{
  if (!(IApplication*)newKompasAPI)
  {
    CString filename;

    if (::GetModuleFileName(NULL, filename.GetBuffer(255), 255))
    {
      filename.ReleaseBuffer(255);
      CString libname;

      libname = LoadStr(IDR_API7);    // kAPI7.dll
      filename.Replace(filename.Right(filename.GetLength() - (filename.ReverseFind('\\') + 1)),
        libname);

      HINSTANCE hAppAuto = LoadLibrary(filename); // идентификатор kAPI7.dll

      if (hAppAuto)
      {
        // Указатель на функцию возвращающую интерфейс KompasApplication  
        typedef LPDISPATCH(WINAPI* FCreateKompasApplication)();

        FCreateKompasApplication pCreateKompasApplication =
          (FCreateKompasApplication)GetProcAddress(hAppAuto, "CreateKompasApplication");

        if (pCreateKompasApplication)
          newKompasAPI = IDispatchPtr(pCreateKompasApplication(), false /*AddRef*/); // Получаем интерфейс Application
        FreeLibrary(hAppAuto);
      }
    }
  }
}



//-------------------------------------------------------------------------------
// Задать идентификатор ресурсов
// ---
unsigned int WINAPI LIBRARYID()
{
  return IDR_LIBID;
}


////////////////////////////////////////////////////////////////////////////////
//
// 
//
////////////////////////////////////////////////////////////////////////////////
class MLibObj : public PropertyManagerObject,
  public ATreeViewEventCallBack
{
protected:
  IPropertyTreePtr            m_tree;             // Дерево
  IPropertyManagerPtr         m_propMng;          // Менеджер панели свойств
  IPropertyTreeNodePtr        m_root;
  ABaseEvent* m_treeViewEvent;

  CMenu                      m_treeMenu; // Меню для дерева 
  bool                       m_currentNodeRequiredDropAfter;


public:
  MLibObj();
  ~MLibObj();

public:
  //  // UserControlEventCallback
  //  virtual bool CallbackCreateOCX ( LPDISPATCH iOcx, long controlID );
  //  virtual bool CallbackDestroyOCX(                  long controlID );

protected:

  // Проинициализировать дерево
  void InitTree(IPropertyTreePtr& ctrl);

public:
  void CreateUserPanel();

  virtual bool OnButtonClick(long buttonID);

  virtual void OnExpandOrCollapse(IPropertyTreeNodePtr Node, bool collapse);
  virtual void OnSelectNodes(const VARIANT& Nodes, bool selected);

  virtual void OnNodeDblClick(IPropertyTreeNodePtr Node);
  virtual void OnBeginEditText(IPropertyTreeNodePtr Node);
  virtual void OnNodeDragStarted(IPropertyTreeNodePtr Node);
  virtual void OnNodeDragOver(IPropertyTreeNodePtr NotifyNode, IPropertyTreeNodePtr DragNode, bool CtrlPressed, bool RequiredDropAfter);
  virtual void OnNodeDragDroped(IPropertyTreeNodePtr NotifyNode, IPropertyTreeNodePtr DragNode, bool CtrlPressed);
  virtual void OnContextMenuRequest(IPropertyTreeNodePtr Node);
  // prControlCommand Нажатие кнопки контрола                                               
  virtual bool OnControlCommand(long ctrlID, long buttonID);

private:
  void CloseTree();
  void InitMenu(bool selected);

};


PArray<MLibObj> m_libObjects;

//-----------------------------------------------------------------------------
//
// ---
MLibObj::MLibObj()
  : m_tree(),
  m_treeViewEvent(nullptr)
{
  m_treeMenu.LoadMenu(IDM_TREE_MENU);
  m_treeMenu.EnableMenuItem(1, MF_BYPOSITION | MF_ENABLED);
  m_currentNodeRequiredDropAfter = false;
}

//-----------------------------------------------------------------------------
//
// ---
MLibObj::~MLibObj()
{
  ABaseEvent::TerminateEvents(GUID_NULL, m_propMng);
}


//-----------------------------------------------------------------------------
//
// ---
void MLibObj::CreateUserPanel()
{
  CRect g_Rect(20, 20, 270, 320);
  m_propMng = newKompasAPI->CreatePropertyManager(TRUE/*FALSE*/);
  if (m_propMng)
  {
    m_propMng->Layout = pmAlignRight;
    m_propMng->Caption = _T("Панель из библиотеки");
    m_propMng->SetGabaritRect(g_Rect.left, g_Rect.top, g_Rect.right, g_Rect.bottom);
    m_propMng->SpecToolbar = pnEnterEscHelp;
    new PropertyManagerEvent(m_propMng, *this);                 // Подписываемся на события процесса 
    IPropertyTabPtr tab(m_propMng->PropertyTabs->Add(_T("Закладка из библиотеки")));

    // Получаем коллекцию контролов
    IPropertyControlsPtr collection = tab->PropertyControls;
    m_tree = collection->Add(ksControlTree);
    if (m_tree)
    {
      m_tree->NameVisibility = ksNameAlwaysVisible;
      m_tree->Name = L"Дерево";
      m_tree->MinHeight = 100;
      m_tree->Resizable = true;
      m_tree->Id = 1000;
      InitTree(m_tree);

      m_treeViewEvent = new ATreeViewEvent(m_tree, *this);
    }
    m_propMng->Caption = _T("Панель из библиотеки1");
    m_propMng->ShowTabs();
  }
}

//-----------------------------------------------------------------------------
//
// ---
bool MLibObj::OnButtonClick(long buttonID)
{
  if (m_tree && buttonID == pbEnter)
  {
    PArray <IPropertyTreeNodePtr> nodes;
    FillDispArray(m_tree->SelectedNodes, nodes);
    Message(_T("Количество селектированных узлов:") + _bstr_t(nodes.Count()));

    if (nodes.Count() == 1)
    {
      auto node = *nodes[0];
      if (node)
      {
        Message(_T("Узел: ") + _bstr_t((node->Expanded ? _T("Раскрытый, ") : _T("Не раскрытый, "))) + _bstr_t(node->IsRootNode ? _T("Корневой") : _T("Не корневой")));
        Message(_T("Количество подчиненных узлов: ") + _bstr_t(node->ChildsCount));
      }
    }
  }
  else
  {
    switch (buttonID)
    {
    case IDM_MENU_COMMAND1:
      MessageT(_T("Нажата кнопка контрола под номером 1"));
      break;
    case IDM_MENU_COMMAND2:
      MessageT(_T("Нажата кнопка контрола под номером 2"));
      break;
    case IDM_MENU_COMMAND3:
      MessageT(_T("Нажата кнопка контрола под номером 3"));
      break;

    case pbEsc:
    {
      CloseTree();
      break;
    }
    }


  }

  return true;
}

//-----------------------------------------------------------------------------
//
// ---
void MLibObj::OnExpandOrCollapse(IPropertyTreeNodePtr Node, bool collapse)
{
  if (Node)
  {
    if (Node->NodeData == 3 || Node->NodeData == 2 || Node->NodeData == 10)
      Node->SetNodeIcon(collapse ? IDB_ROOT : IDB_ROOTSELECT, L"");

    MessageT(_bstr_t(collapse ? _T("Свернули узел - ") : _T("Развернули узел - ")) + Node->Text);
  }
}

//-----------------------------------------------------------------------------
//
// ---
void MLibObj::OnSelectNodes(const VARIANT& Nodes, bool selected)
{
  PArray<IPropertyTreeNodePtr> nodesArr;
  FillDispArray(Nodes, nodesArr);

  if (nodesArr.Count())
  {
    _bstr_t message = selected ? _T("Селектированы узлы: ") : _T("Снято селектирование с : ");

    for (uint i = 0, count = nodesArr.Count(); i < count; ++i)
    {
      IPropertyTreeNodePtr node = *nodesArr[i];
      if (node)
      {
        message += node->Text;
        if (i != count - 1)
          message += _bstr_t(_T(", "));
      }
    }

    MessageT(message);
  }
}


//-------------------------------------------------------------------------------------
// Клик по узлу дерева
// ---
void MLibObj::InitMenu(bool selected)
{
  IPropertyControl1Ptr control1(m_tree);
  if (control1)
  {
    if (selected)
    {
      CMenu* subMenu = m_treeMenu.GetSubMenu(0 /*индекс подменю*/);
      control1->UserMenu = PtrToLong(subMenu->m_hMenu);
    }
    else
    {
      control1->UserMenu = 0l;
    }
  }
}

//-----------------------------------------------------------------------------
//
// ---
void MLibObj::OnNodeDblClick(IPropertyTreeNodePtr node)
{
  if (node)
    MessageT(_bstr_t(_T("Двойной клик по : ")) + node->Text);
}

//-----------------------------------------------------------------------------
//
// ---
void MLibObj::OnBeginEditText(IPropertyTreeNodePtr node)
{
  if (node && ::YesNo("Отредактировать узел дерева?") == 1)
    node->EditText();
}

//-----------------------------------------------------------------------------
//
// ---
void MLibObj::OnNodeDragStarted(IPropertyTreeNodePtr Node)
{
  if (Node)
  {
    if (!Node->IsRootNode)
      Node->DragPermitted = TRUE;


  }
}

void MLibObj::OnNodeDragOver(IPropertyTreeNodePtr NotifyNode, IPropertyTreeNodePtr DragNode, bool CtrlPressed, bool RequiredDropAfter)
{
  m_currentNodeRequiredDropAfter = RequiredDropAfter;
  //_bstr_t traceName = L"NotifyNode : " + NotifyNode->Text + L"DragNode : " + DragNode->Text + "\n";
  //TRACE("%S", traceName.GetBSTR());
  if (NotifyNode && NotifyNode != DragNode && DragNode)
  {
    if (DragNode->NodeData == 3 || DragNode->NodeData == 2)
      NotifyNode->DropPermission = ksDropAfter;
    else
    {
      if (NotifyNode->NodeData == 3 || NotifyNode->NodeData == 2 || NotifyNode->NodeData == 10)
        NotifyNode->DropPermission = ksDropInto;
      else
        NotifyNode->DropPermission = ksDropAfter;
    }
  }
}

void MLibObj::OnNodeDragDroped(IPropertyTreeNodePtr NotifyNode, IPropertyTreeNodePtr DragNode, bool CtrlPressed)
{
  if (DragNode && NotifyNode && NotifyNode != DragNode)
  {
    if (m_currentNodeRequiredDropAfter)
    {
      NotifyNode->MoveNodes(m_tree->SelectedNodes, DragNode);
    }
    else if (NotifyNode->NodeData == 3 || NotifyNode->NodeData == 2 || NotifyNode->NodeData == 10)
    {
      NotifyNode->MoveNodes(m_tree->SelectedNodes, nullptr);
    }


  }
}

//-----------------------------------------------------------------------------
//
// ---
void MLibObj::OnContextMenuRequest(IPropertyTreeNodePtr node)
{
  InitMenu(node);
}


//-----------------------------------------------------------------------------
//
// ---
bool MLibObj::OnControlCommand(long ctrlID, long buttonID)
{
  if (m_tree && buttonID == IDM_USERMENU_COMMAND1)
  {
    PArray<IPropertyTreeNodePtr> nodeArr;
    FillDispArray(m_tree->SelectedNodes, nodeArr);

    if (nodeArr.Count())
    {
      auto node = *nodeArr[nodeArr.Count() - 1];
      if (node)
      {
        OnBeginEditText(node);
        return true;
      }
    }
  }

  return false;
}

void MLibObj::CloseTree()
{
  delete m_treeViewEvent;
  m_treeViewEvent = nullptr;

  if (m_tree)
  {
    ABaseEvent::TerminateEvents(DIID_ksPropertyManagerNotify);
    m_propMng->HideTabs();
    m_propMng = nullptr;
    m_tree = nullptr;
  }
}

_bstr_t GetLibraryIconFont()
{
  static _bstr_t iconfont;
  if (iconfont.length() == 0 && newKompasAPI)
  {
    IProceduresLibraryPtr lib(newKompasAPI->LibraryManager->ProceduresLibraries->Item[(LPCTSTR)LoadStr(LIBRARYID())]);
    if (lib)
      iconfont = lib->IconsFont;
  }
  return iconfont;
}

//-----------------------------------------------------------------------------
/// Проинициализировать дерево
// ---
void MLibObj::InitTree(IPropertyTreePtr& tree)
{
  IPropertyToolBarPtr toolbar(tree);
  if (toolbar)
  {
    toolbar->AddButton(IDM_MENU_COMMAND1, 0xECA6, -1);
    toolbar->ButtonEnable[IDM_MENU_COMMAND1] = true;
    toolbar->ButtonTips[IDM_MENU_COMMAND1] = L"Кнопка 1";

    toolbar->AddButton(IDM_MENU_COMMAND2, 0xECA7, -1);
    toolbar->ButtonEnable[IDM_MENU_COMMAND2] = false;
    toolbar->ButtonTips[IDM_MENU_COMMAND2] = L"Кнопка 2";

    toolbar->AddButton(IDM_MENU_COMMAND3, 0xECA8, -1);
    toolbar->ButtonEnable[IDM_MENU_COMMAND3] = true;
    toolbar->ButtonTips[IDM_MENU_COMMAND3] = L"Кнопка 3";

    toolbar->AddButton(IDM_MENU_COMMAND4, 0xECA9, -1);
    toolbar->ButtonVisible[IDM_MENU_COMMAND4] = false;

  }

  m_root = tree->CreateNode(_T("Корневой узел"));
  m_root->NodeData = 10;
  if (m_root)
  {
    m_root->SetNodeIcon(IDB_ROOT, L"");
    m_root->DropPermission = ksDropInto;

    tree->AddNode(m_root);
    tree->EnableDrag = TRUE;

    auto node1 = tree->CreateNode(_T("Узел_1."));
    node1->NodeData = 1;

    m_root->AddNode(node1, nullptr);

    auto nodes1 = tree->CreateNode(_T("Папка_1"));
    nodes1->SetNodeIcon(IDB_ROOT, L"");
    nodes1->NodeData = 2;

    m_root->AddNode(nodes1, nullptr);

    auto nodes2 = tree->CreateNode(_T("Папка_2"));
    nodes2->SetNodeIcon(IDB_ROOT, L"");
    nodes2->NodeData = 3;

    m_root->AddNode(nodes2, nodes1);

    auto node2 = tree->CreateNode(_T("Узел_2"));
    node2->NodeData = 4;

    nodes2->AddNode(node2, nullptr);

    nodes2 = tree->FindNodeByName(_T("Папка_1"));
    if (nodes2)
    {
      nodes2->AddNode(tree->CreateNode(_T("Узел_3")), nullptr);
    }
  }
}


//-------------------------------------------------------------------------------
// Головная функция библиотеки
// ---
void WINAPI LIBRARYENTRY(unsigned int comm)
{
  GetNewKompasAPI();
  if (newKompasAPI)
  {
    switch (comm)
    {
    case 1:
    {
      MLibObj* obj = new MLibObj();
      m_libObjects.Add(obj);
      obj->CreateUserPanel();
    }
    break;
    }
  }
}


//-------------------------------------------------------------------------------
// Завершение приложения
// ---
void OnProcessDetach()
{
  m_libObjects.Flush();
  ABaseEvent::TerminateEvents();
  ABaseEvent::DestroyList();

  newKompasAPI = nullptr;
}


//------------------------------------------------------------------------------
// Загрузить строку из ресурса
// ---
CString LoadStr(int strID)
{
  TCHAR temp[_MAX_PATH];
  LoadString(IPropertyTree_SampleDLL.hModule, strID, temp, _MAX_PATH);
  return temp;
}



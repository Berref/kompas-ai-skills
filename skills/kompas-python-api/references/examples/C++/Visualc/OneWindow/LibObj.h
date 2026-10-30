#ifndef __CPAR_H
#define __CPAR_H
////////////////////////////////////////////////////////////////////////////////
//
// LibObj.h
// <LibObj.cpp>
//
////////////////////////////////////////////////////////////////////////////////
#include "resource.h"
#include "PropManager\CPropMen.h"
#include "Events\DocumentFrameEvent.h"
#include <PArray.h>
#include <SArray.h>
#include <vector>

#define   NULL_EPSILON      1E-30 // погрешность для проверки на равенство нулю

struct Matrix3D;

//-----------------------------------------------------------------------------
// 3D точка
// ---
struct Point3D
{
  double x;
  double y;
  double z;
  Point3D()
    : x(0.0)
    , y(0.0)
    , z(0.0) {}
  Point3D(double _x, double _y, double _z)
    : x(_x)
    , y(_y)
    , z(_z) {}

  Point3D(Point3D& other)
    : x(other.x)
    , y(other.y)
    , z(other.z) {}

  Point3D& operator-=(const Point3D& other)
  {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
  }

  void Transform(const Matrix3D& mtr);
};


//-----------------------------------------------------------------------------
// 3D вектор
// ---
struct Vector3D
{
  double x;
  double y;
  double z;
  Vector3D()
    : x(0.0)
    , y(0.0)
    , z(0.0) {}
  Vector3D(double _x, double _y, double _z)
    : x(_x)
    , y(_y)
    , z(_z) {}

  Vector3D(Vector3D& other)
    : x(other.x)
    , y(other.y)
    , z(other.z) {}

};



//-----------------------------------------------------------------------------
//
// ---
struct Matrix3D
{
  double el[4][4];
  Matrix3D() { Init(); } // Единичная матрица 

  Matrix3D(Point3D& original, // Точка привязки
    Vector3D& normal,   // Единичный вектор 
    Vector3D& axisX,    // Единичный вектор
    Vector3D& axisY)   // Единичный вектор
  {
    Init(original, normal, axisX, axisY);
  }

  // Инициализация по параметрам математической поверхности  
  Matrix3D(ISurface& surf,
    bool       isSameSense,  // совпадает ли направление с нормалью поверхности или оно противоположное 
    double     u,      // Единичный вектор 
    double     v)     // Единичный вектор
  {
    Init(surf, isSameSense, u, v);
  }

  // Для получения из SafeArray-я
  Matrix3D(double* el16);

  Vector3D& GetAxisX() const { return (Vector3D&)*el[0]; } // Единичный вектор
  Vector3D& GetAxisY() const { return (Vector3D&)*el[1]; } // Единичный вектор
  Vector3D& GetAxisZ() const { return (Vector3D&)*el[2]; } // Единичный вектор
  Point3D& GetOrigin() const { return (Point3D&)*el[3]; }

  void      Init(); // Единичная матрица   

  void      Init(Point3D& original, // Точка привязки
    Vector3D& normal,   // Единичный вектор 
    Vector3D& axisX,    // Единичный вектор
    Vector3D& axisY);  // Единичный вектор

  void      Init(ISurface& surf,   // Математическая поверхность
    bool isSameSense,  // совпадает ли направление с нормалью поверхности или оно противоположное
    double     u,      // параметр u 
    double     v);    // параметр v;   

  void      Init(const Matrix3D& A, const Matrix3D& B); // Умножение

  void        operator *= (const Matrix3D& m) { Multiply(m); } // умножение на матрицу

  bool        operator == (const Matrix3D& m) const; // чёткое сравнение (точность - Math3D::lengthEpsilon)

  void        Multiply(const Matrix3D& b); // умножение на матрицу this = this * b;

  void        Div(Matrix3D&) const; // обращение квадратной матрицы  

};


//-----------------------------------------------------------------------------
// Параметры внешнего объекта с триангуляцией
// ---
struct ExternalTeselationParam
{
  _variant_t       points;        // Координаты вершин
  _variant_t       normals;       // Координаты нормалей
  _variant_t       indexes;       // Индексы вершин
  //    _variant_t colors;    // Цвета в вершинах
  // AdvancedColor                        
  COLORREF         color;         // Цвет 
  double           ambient;       // общий свет
  double           diffuse;       // диффузия
  double           specularity;   // зеркальность
  double           shininess;     // блеск 
  double           transparency;  // прозрачность
  double           emission;      // излучение
  bool             edge;
  ExternalTeselationParam(IEntityPtr& obj, IPartPtr& topPart);
  ExternalTeselationParam(PArray<ExternalTeselationParam>& params);

  bool IsValid()
  {
    return transparency > 0.0 &&
      points.vt == (VT_ARRAY | VT_R8) &&
      indexes.vt == (VT_ARRAY | VT_I4);
  }

  void Init(IExternalTessellationObjectPtr& obj)
  {
    if (obj)
    {
      if (edge)
      {
        obj->SetEdges(points, indexes, _variant_t()/*colors*/);
      }
      else
        obj->SetTessellation(points, indexes, normals, _variant_t()/*colors*/);
      obj->SetAdvancedColor(color, ambient, diffuse, specularity, shininess, transparency, emission);
    }
  }

  void InitByFace(IFaceDefinitionPtr& faceDef);
  void InitByEdge(IEdgeDefinitionPtr& edgeDef);

  void PacEdges(PArray<ExternalTeselationParam>& params); // Упаковать параметры ребер в один элемент

};

//-----------------------------------------------------------------------------
//
// ---
struct TeselationNodeParam
{
  PArray<IFaceDefinitionPtr>      m_faces;   // Стрелка
  SArray<long>                    m_iids;    // Идентификаторы внешних объектов для стрелок 
  long                            m_index;   // Индекс 
  bool                            m_visible; // Видимость стрелок
  _bstr_t                         m_name;    // Имя узла соответствующего стрелкам

  TeselationNodeParam() : m_index(0), m_visible(false) {}

  virtual ~TeselationNodeParam() {}

  long GetID() { return m_index; }

  virtual void Save(_bstr_t& pasword, IUserDataStoragePtr& s);
  virtual bool Load(IUserDataStoragePtr& s, long version, long index);

};


//-----------------------------------------------------------------------------
//
// ---
struct ArrowParam : public TeselationNodeParam
{
  ArrowParam() : TeselationNodeParam() {}

  virtual ~ArrowParam() {}

  void Make(IFaceDefinitionPtr& face, IDocumentFramePtr& frame, PArray<ExternalTeselationParam>& arrowParams);

  void Make(IDocumentFramePtr& frame, PArray<ExternalTeselationParam>& arrowParams);
};



////////////////////////////////////////////////////////////////////////////////
//
// Базовый класс элемента
//
////////////////////////////////////////////////////////////////////////////////
class LibObj : public PropertyManagerObject,
  public DocumentFrameEventCalback,
  public ATreeViewEventCallBack
{
protected:
  int            m_command;
  bool           m_LoadTree;            // Загружено ли дерево  

  bool                  m_TreeVisible;  // Видимость дерева  
  IPropertyTreePtr      m_TreeCtrl;     // Дерево

  ABaseEvent* m_documentFrameEvent;

  IPropertyManagerPtr m_propMng; // менеджер панели свойств
  IPropertyTreeNodePtr m_arrrowsNode;
  std::vector <IPropertyTreeNodePtr> m_selectedNodes;

  ABaseEvent* m_treeViewEvent;

  static            LibObj* editObj;   // Редактируемый объект

  IPropertyTabPtr m_tab;

  // Стрелки ---
  PArray<ExternalTeselationParam>   arrowParams; // Стрелка
  std::vector<ArrowParam*>           m_arrows; // Массив, содержащий нагрузки

  ArrowParam* m_newArrow;
  long                            m_arrowsIndex; // Счетчик для стрелок

  long m_currentCommand;

  //---

  CMenu                              m_treeMenu; // Меню для дерева 

public:
  // Конструкторы 
  LibObj(IDocumentFramePtr& frame);
  virtual ~LibObj();

  bool              IsMyFrame(IDocumentFramePtr& frame);
  IDocumentFramePtr GetFrame();                                 // Получить окно 

  void              CreateForce();                              // Создание диформационной нагрузки
  void              OnOfTree();                                 // Показать скрыть дерево   

  void              Refresh();                                  // Пересчитать нагрузки             

  void              CreateTree();                               // Создание дерева нагрузок в окне документа
  void              CloseTree();                                // Удаление дерева нагрузок
  void              SaveTree();                                 // Сохранить дерево в документ
  void              LoadTree();                                 // Считать дерево из документа

  IUserDataStoragePtr GetUserDataStorageByName(const _bstr_t& treeName);

  void              FillTree(IPropertyTreePtr& tree);          // Накачка дерева

  bool              CheckIfArrowNode(IPropertyTreeNodePtr node);

  void              FillTreeNodes(std::vector<ArrowParam*>& nodeElements);  // Наполним узлы дерева

  // Менеджер свойств ##################################################################
    // События     
    // prButtonClick - Нажатие кнопки.
  virtual bool OnButtonClick(long buttonID);

  //prChangeControlValue - Изменение значения контрола
  virtual bool OnChangeControlValue( /*IPropertyControl* cntrl,*/ long ctrlID, const VARIANT& newVal);

  // prControlCommand Нажатие кнопки контрола
  virtual bool OnControlCommand(long ctrlID, long buttonID);

  // prButtonUpdate        - Установка состояния кнопки спецпанели.
  virtual bool OnButtonUpdate(long buttonID, long* check, VARIANT_BOOL* _enable);

  // Виртуальная функция наполнения контролов элемента
  virtual void       ShowControls();
  // Менеджер свойств ##################################################################

  // DocumentFrameEventCalback #########################################################
    // frBeginPaintGL        - Начало создания листа в контексте OpenGL
  virtual BOOL BeginPaintGL(IDocumentFramePtr& docFrame, ksGLObjectPtr& glObj, long drawMode);
  // frAddGabarit          - Определение габаритов документа
  virtual BOOL AddGabarit(IDocumentFramePtr& docFrame, IGabaritObjectPtr& gabObj);
  // frCloseFrame          - Закрытие окна
  virtual BOOL CloseFrame(IDocumentFramePtr& docFrame);
  // DocumentFrameEventCalback #########################################################

  // ATreeCtrlEventCallBack #########################################################
  virtual void OnExpandOrCollapse(IPropertyTreeNodePtr node, bool collapse) override;
  virtual void OnSelectNodes(const VARIANT& Nodes) override;
  virtual void OnUnselectNodes(const VARIANT& Nodes) override;
  virtual void OnMenuCommand(long Id);
  virtual void OnBeginTextEdit(IPropertyTreeNodePtr node) override;
  virtual void OnEndTextEdit(IPropertyTreeNodePtr node) override;
  virtual void OnContextMenuRequest(IPropertyTreeNodePtr node) override;
  void InitMenu(int menuType);
  // ATreeCtrlEventCallBack #########################################################


  static bool WINAPI LibObj::SELECTFILTERPROC(IEntity* entity);
  static int  WINAPI LibObj::SELECTCALLBACKPROC(IEntity* entity, IRequestInfo* info);

  BOOL OnSelectFace(IFaceDefinitionPtr& face);
  void CreateForce(IFaceDefinitionPtr& face); // Создание диформационной нагрузки

  void SelectFacesForForce();
  void SelectFaces(long procID, long promtID);

  void OnOffTesselations(SArray<long>& iids, bool vis, bool oldVis, bool del);

  // Добавление узла дерева
  bool AddNode(const _bstr_t& nodeName, int index);

  LPCTSTR MakeNodeName(LPCTSTR name, int index);

  bool IsArrowsVisible();
  void MakeTessellations();
  void OffAllTessellations();
  void LoadArrowParams();
};


////////////////////////////////////////////////////////////////////////////////
// Прочее
//
bool GetFullName(LPCTSTR inName, LPTSTR outName, int outNameLen);
LibObj* FindOrCreateLibObj(IDocumentFramePtr& docFrame, bool create);

void   GetNewKompasAPI();

//------------------------------------------------------------------------------
// Поиск элемента в массиве
// ---
template <class T>
int FindT(T& o, SArray<T>& arr) {
  for (int i = 0, count = arr.Count(); i < count; i++)
    if (o == arr[i])
      return i;
  return -1;
}

//------------------------------------------------------------------------------
// Поиск элемента в массиве
// ---
template <class T>
int FindT(T& o, PArray<T>& arr) {
  for (int i = 0, count = arr.Count(); i < count; i++)
    //    if ( !memcmp( &o, &arr[i], sizeof(T) ) )
    if (o == *arr[i])
      return i;
  return -1;
}

//------------------------------------------------------------------------------
// Поиск объекта с идентификатором id
// ---
template <class T>
int GetIndexByID(long id, PArray<T>& arr) {
  if (id) {
    for (int i = 0, count = arr.Count(); i < count; i++)
      if (arr[i]->GetID() == id)
        return i;
  }
  return -1;
}

extern AFX_EXTENSION_MODULE OneWindowDLL;
#endif

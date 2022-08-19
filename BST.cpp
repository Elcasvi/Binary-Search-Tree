#include "BST.h"
#include "TreeNode.h"
#include <iostream>
#define SPACE 10
using namespace std;


BST::BST()
  {
    root=NULL;
  }
  bool BST::isEmpty()
  {
    if(root==NULL)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  void BST::insertNode(TreeNode* new_node)
  {
    if(root==NULL)
    {
      root=new_node;
      cout<<"Valor insertado como raiz del nodo"<<endl;
    }
    else
    {
      TreeNode* temp=root;
      while(temp!=NULL)
      {
        if(new_node->value==temp->value)
        {
          cout<<"Ese valor ya existe , ingresa uno diferente "<<endl;
          return;
        }
        else if((new_node->value<temp->value)&&(temp->left==NULL))
        {
          temp->left=new_node;
          cout<<"Valor ingresado a la izquierda "<<endl;
          break;
        }
        else if(new_node->value<temp->value)
        {
          temp=temp->left;
        }
        else if((new_node->value>temp->value)&&(temp->right==NULL))
        {
          temp->right=new_node;
          cout<<"Valor ingresado a la derecha "<<endl;
          break;
        }
        else
          temp=temp->right;
      }
    }
  }


  ///Imprimir
  void BST::print2D(TreeNode* r,int space)
  {
   if(r==NULL)
   {
     return;
   }
   space+=SPACE;
   print2D(r->right,space);
   cout<<endl;
   for(int i=SPACE;i<space;i++)
   {
     cout<<" ";
   }
   cout<<r->value<<"\n";
   print2D(r->left,space);
  }

  void BST::printPreorder(TreeNode* r)///(Raiz,Izquierda,Derecha)
  {
    if(r==NULL)
    {
      return;
    }
    ///Primero imprime la informacion del nodo
    cout<<r->value<<" ";
    ///Deespues recorre el sub arbol izquierdo
    printPreorder(r->left);
    ///Ahora el lado derecho
    printPreorder(r->right);
  }

  void BST::printInorder(TreeNode* r)///(Izquierda,Raiz,Derecha)
  {
    if(r==NULL)
    {
      return;
    }
    ///Primero recorremos la parte derecha
    printInorder(r->left);
    ///Despues imprimimos los datos del nodo
    cout<<r->value<<" ";
    ///Ahora recorremos la parte derecha
    printInorder(r->right);
  }

  void BST::printPostorder(TreeNode* r)///(Izquierda,Derecha,Raiz)
  {
    if(r==NULL)
    {
      return;
    }
    ///Primero recorremos el sub arbol izquierdo
    printPostorder(r->left);
    ///Despues el sub arbol derecho
    printPostorder(r->right);
    ///Ahora imprimimos los nodos
    cout<<r->value<<" ";
  }

  TreeNode* BST::iterativeSearch(int val)
  {
    if(root==NULL)
    {
      return root;
    }
    else
    {
      TreeNode *temp=root;
      while(temp!=NULL)
      {
        if(val==temp->value)
        {
          return temp;
        }
        else if(val<temp->value)
        {
          temp=temp->left;
        }
        else
        {
          temp=temp->right;
        }
      }
      return NULL;
    }
  }

  int BST::height(TreeNode* r)
  {
    if(r==NULL)
    {
      return -1;
    }
    else
    {
      ///calcular la altura de cada sub arbol
      int lheight=height(r->left);
      int rheight=height(r->left);

      ///Usar la forma larga
      if(lheight>rheight)
      {
        return (lheight+1);
      }
      else
      {
        return (rheight+1);
      }
    }
  }

  ///Imprimir nodos a un cierto nivel
  void BST::printGivenLevel(TreeNode* r,int level)
  {
    if(r==NULL)
    {
      return;
    }
    else if(level==0)
    {
      cout<<r->value<<" ";
    }
    else ///Nivel 0
    {
      printGivenLevel(r->left,level-1);
      printGivenLevel(r->right,level-1);
    }
  }

  void BST::printLevelOrderBFS(TreeNode* r)
  {
    int h=height(r);
      for(int i=0;i<=h;i++)
      {
        printGivenLevel(r,i);
      }
  }

  TreeNode* BST::minvalueNode(TreeNode* node)
  {
    TreeNode* current=node;
    ///Cicla para baja hsata encontrar la hoja izquierda
    while(current->left!=NULL)
    {
      current=current->left;
    }
    return current;
  }

  TreeNode* BST::deleteNode(TreeNode* r,int v)
  {
    ///Caso base
    if(r==NULL)
    {
      return NULL;
    }
    ///si el dato que va a ser eliminada es mas chico que el dato raiz
    ///entonces se recarga en el sub arbol izquierdo
    else if(v<r->value)
    {
      r->left=deleteNode(r->left,v);
    }

    ///Si el dato es igual al dato de la raiz , etonces este el nodo correcto a eliminar
    else
    {
      if(r->left==NULL)
      {
        TreeNode* temp=r->right;
        delete r;
        return temp;
      }
      else if(r->right==NULL)
      {
        TreeNode* temp=r->left;
        delete r;
        return temp;
      }
      else
      {
        ///Nodo con dos hijos: Obtener el sucesor inorder (El mas chico en el sub arbol)
        TreeNode* temp=minvalueNode(r->right);
        ///Copiar el contenido del sucesor inorder a este nodo
        r->value=temp->value;
        ///Eliminar eñl sucesor inorder
        r->right=deleteNode(r->right,temp->value);
        //Elminar nodo(r->right, temp->value);
      }
    }
    return r;
  }

  bool BST::ancestors(TreeNode *r, int target)
    {
        if (r == NULL)
            return false;
        if (r->value == target)
            return true;
        if (ancestors(r->left, target) || ancestors(r->right, target))
        {
            cout << root->value << " ";
            return true;
        }
        return false;
    }


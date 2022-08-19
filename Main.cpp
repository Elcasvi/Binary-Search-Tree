#include "BST.h"
#include "TreeNode.h"
#include <iostream>
using namespace std;

int main()
{
    BST obj;
    int opcion,val;
    do {


        // Texto del menú que se verá cada vez
        cout << "\n\nMenu de Opciones" << endl;
        cout << "1. Insertar nodo" << endl;
        cout << "2. Buscar nodo" << endl;
        cout << "3. Eliminar un nodo" << endl;
        cout << "4. Imprimir los valores del BST" << endl;
        cout << "5. Altura del arbol" << endl;
        cout << "6. Ancestro de un dato"<<endl;
        cout << "7. Limpiar terminal" << endl;
        cout << "0. SALIR" << endl;

        cout << "\nIngrese una opcion: ";
        cin >> opcion;
        TreeNode *new_node=new TreeNode();

        switch (opcion) {
            case 1:
                /// Insertar un nodo
                cout<<"--Ingresar un nodo-- "<<endl;
                cout<<"Ingresa el valor del nodo para insertar en el BST: ";
                cin>>val;
                new_node->value=val;
                obj.insertNode(new_node);
                cout<<endl;
                break;
            case 2:
                ///Buscar un nodo
                cout<<"Buscar un nodo: "<<endl;
                cout<<"Ingresa el valor a buscar en el arbol binario: ";
                cin>>val;
                new_node=obj.iterativeSearch(val);
                if(new_node!=NULL)
                {
                  cout<<"Valor encontrado"<<endl;
                }
                else
                {
                  cout<<"Valor no encontrado"<<endl;
                }
                break;
            case 3:
                /// Eliminar un nodo
                cout<<"Eliminar un nodo: "<<endl;
                cout<<"Ingresa el valor del nodo a ser eliminado en arbol binario: ";
                cin>>val;
                new_node=obj.iterativeSearch(val);
                if(new_node!=NULL)
                {
                  obj.deleteNode(obj.root,val);
                  cout<<"Valor elminado"<<endl;
                }
                else
                {
                  cout<<"Valor no encontrado"<<endl;
                }
                break;
            case 4:
                /// Imprimir valoeres del BST
                cout<<"--Imprimir arbol-- "<<endl;
                obj.print2D(obj.root,5);
                cout<<endl<<endl;

                cout<<"--Imprimir el nivel BFS---"<<endl;
                obj.printLevelOrderBFS(obj.root);
                cout<<endl<<endl;

                cout<<"--Preorder--\n";
                obj.printPreorder(obj.root);
                cout<<endl<<endl;

                cout<<"--Inorder-- \n";
                obj.printInorder(obj.root);
                cout<<endl<<endl;

                cout<<"--Postorder-- \n";
                obj.printPostorder(obj.root);
                break;
            case 5:
              cout<<"--Altura del arbol binario--"<<endl;
              cout<<"Altura: "<<obj.height(obj.root)<<endl;
              break;
            case 6:
              cout<<"--Ancestro de un nodo--"<<endl;
              cout<<"Ingresa el valor del nodo para buscar su ancestro: ";
              cin>>val;
             obj.ancestors(obj.root,val);
             cout<<endl;
              break;
            case 7:
             ///Limpiar terminal
              system("cls");
              break;
            case 0:
              ///Terminar el programa
            	cout<<"Hasta la proxima!!!"<<endl;
            	break;
        }
    } while (opcion!=0);


  return 0;
}


#include<stdio.h>
#include<conio.h>
#define password "m1213v"
#include "Head.c"
#include "member.c"
#include "trainer.c"
#include "m.c"
#include "equipmen.c"
void main()
{
	int m_op,s_op,l_op,choice,i,eop,temp;
	char pass[10],ch;
	login:
	clrscr();
	heading();
	line();
	printf("\n\t\t\t\t LOGIN \n");
	line();
	printf("\t\t\t\t1.Admin Login\n\t\t\t\t2.User Login\n\t\t\t\t3.Exit\n");
	printf("\t\t\t\tYour option is : ");
	scanf("%d",&l_op);
	switch(l_op)
	{
		case 1:
			admin:
			clrscr();
			heading();
			line();
			printf("\n\t\t\t\tADMIN LOGIN\n");
			line();
			printf("\n\t\t\t\tEnter the password : ");
			for(i=0;i<6;i++)
			{
				ch=getch();
				pass[i]=ch;
				printf("*");
			}
			pass[i]='\0';
			if(strcmp(pass,password)==0)
			{
			    printf("\n\t\t\t\t\"Now you can access admin part\" ");
			    getch();
				mainmenu:
				clrscr();
				heading();
				line();
				printf("\n\t\t\t\tMAIN MENU \n");
				line();
				printf("\t\t\t\t1.Member Menu\n\t\t\t\t2.Trainer Menu\n\t\t\t\t3.Equipment Menu\n\t\t\t\t4.Membership\n\t\t\t\t5.Exit\n");
				printf("\t\t\t\tYour option is : ");
				scanf("%d",&m_op);
				switch(m_op)
				{
					case 1:
						member_menu:
						clrscr();
						heading();
						line();
						printf("\n\t\t\t\tMEMBER MENU\n");
						line();
						printf("\t\t\t\t1.Add Member\n\t\t\t\t2.Edit Member\n\t\t\t\t3.Remove Member\n\t\t\t\t4.Search Member\n\t\t\t\t5.View Member\n\t\t\t\t6.GYM Fees receipt\n\t\t\t\t7.Main Menu\n\t\t\t\t8.Exit\n");
						printf("\t\t\t\tYour option is : ");
						scanf("%d",&m_op);
						switch(m_op)
						{
							case 1:
								clrscr();
								heading();
								add_member();
								getch();
								goto member_menu;

							case 2:
								clrscr();
								heading();
								printf("List of Members : \n");
								view_member();
								getch();
								clrscr();
								heading();
								edit_membe();
								getch();
								goto member_menu;
							case 3:
								clrscr();
								heading();
								printf("List of Members : \n");
								view_member();
								getch();
								clrscr();
								heading();
								remove_mem();
								getch();
								goto member_menu;
							case 4:
								search_menu:
								clrscr();
								heading();
								line();
								printf("\n\t\t\t\tSEARCH MEMBER\n");
								line();
								printf("\t\t\t\t1.BY ID\n\t\t\t\t2.BY NAME\n\t\t\t\t3.BY Purpose\n\t\t\t\t4.Member Menu\n\t\t\t\t5.Exit\n");
								printf("\t\t\t\tYour option is : ");
								scanf("%d",&s_op);
								switch(s_op)
								{
									case 1:
										clrscr();
										heading();
										i_search();
										getch();
										goto search_menu;

									case 2:
										clrscr();
										heading();
										n_search();
										getch();
										goto search_menu;

									case 3:
										clrscr();
										heading();
										p_search();
										getch();
										goto search_menu;

									case 4:
										goto member_menu;

									case 5:
										exit(0);

									default:
										printf("       \t\t\t\"!Please enter valid option !\"\n\n       \t\t\t");
										system("pause");//getch();
										goto search_menu;

								}

							case 5:
								clrscr();
								heading();
								view_member();
								getch();
								goto member_menu;
							case 6:
								clrscr();
								heading();
								printf("List of Members : \n");
								view_member();
								getch();
								clrscr();
								heading();
								feereceipt();
								getch();
								goto member_menu;
							case 7:
								goto mainmenu;
							case 8:
								exit(0);
							default :
								printf("       \t\t\t\"!Please enter valid option !\"\n\n       \t\t\t");
								system("pause");//getch();
								goto member_menu;
						}

					case 2:
						trainer_menu:
						clrscr();
						heading();
						line();
						printf("\n\t\t\t\tTRAINER MENU\n");
						line();
						printf("\t\t\t\t1.Add Trainer\n\t\t\t\t2.Edit Trainer\n\t\t\t\t3.Search Trainer\n\t\t\t\t4.Remove Trainer\n\t\t\t\t5.View Trainer\n\t\t\t\t6.Main Menu\n\t\t\t\t7.Exit\n");
						printf("\t\t\t\tYour option is : ");
						scanf("%d",&m_op);
						switch(m_op)
						{
							case 1:
								clrscr();
								heading();
								add_trainer();
								getch();
								goto trainer_menu;

							case 2:
								clrscr();
								heading();
								printf("List of Trainers : \n");
								view_trainer();
								getch();
								clrscr();
								heading();
								edit_trainer1();
								getch();
								goto trainer_menu;

							case 3:
								s_menu:
								clrscr();
								heading();
								line();
								printf("\n\t\t\t\tSEARCH TRAINER\n");
								line();
								printf("\t\t\t\t1.BY ID\n\t\t\t\t2.BY NAME\n\t\t\t\t3.BY Type\n\t\t\t\t4.Trainer Menu\n\t\t\t\t5.Exit\n");
								printf("\t\t\t\tYour option is : ");
								scanf("%d",&s_op);
								switch(s_op)
								{
									case 1:
										clrscr();
										heading();
										id_search();
										getch();
										goto s_menu;

									case 2:
										clrscr();
										heading();
										na_search();
										getch();
										goto s_menu;

									case 3:
										clrscr();
										heading();
										t_search();
										getch();
										goto s_menu;

									case 4:
										goto trainer_menu;

									case 5:
										exit(0);

									default:
										printf("       \t\t\t\"!Please enter valid option !\"\n\n       \t\t\t");
										system("pause");//getch();
										goto s_menu;

								}

							case 4:
								clrscr();
								heading();
								printf("List of Trainers : \n");
								view_trainer();
								getch();
								clrscr();
								heading();
								remove_trainer();
								getch();
								goto trainer_menu;

							case 5:
								clrscr();
								heading();
								view_trainer();
								getch();
								goto trainer_menu;

							case 6:
								goto mainmenu;
							case 7:
								exit(0);
							default :
								printf("       \t\t\t\"!Please enter valid option !\"\n\n       \t\t\t");
								system("pause");//getch();
								goto trainer_menu;
							}

						case 3:
							equip_menu:
							clrscr();
							heading();
							line();
							printf("\n\t\t\t\tEQUIPMENT MENU\n");
							line();
							printf("\t\t\t\t1.Add Equipment\n\t\t\t\t2.Search Equipment\n\t\t\t\t3.View Equipment\n\t\t\t\t4.Remove Equipment\n\t\t\t\t5.Main Menu\n\t\t\t\t6.Exit\n");
							printf("\t\t\t\tYour option is : ");
							scanf("%d",&m_op);
							switch(m_op)
							{
								case 1:
									eop_menu:
									clrscr();
									heading();
									line();
									printf("\n\t\t\t\tAdd Equipment\n");
									line();
									printf("\t\t\t\t1.Existing Equipment(change quantity)\n\t\t\t\t2.Add new equipment\n\t\t\t\t3.Equipment Menu\n\t\t\t\t4.Exit\n");
									printf("\t\t\t\tYour option is : ");
									scanf("%d",&eop);
									switch(eop)
									{
										case 1:
											clrscr();
											heading();
											printf("\nList of existing equipments is \n ");
											view();
											getch();
											clrscr();
											heading();
											ee_add();
											getch();
											goto equip_menu;

										case 2:
											clrscr();
											heading();
											add_equipment();
											getch();
											goto equip_menu;

										case 3:
										       goto equip_menu;
										case 4:
											exit();
										default :
											printf("       \t\t\t\"!Please enter valid option !\"\n\n       \t\t\t");
											system("pause");//getch();
										       goto eop_menu;
									}

								case 2:
									sea_menu:
									clrscr();
									heading();
									line();
									printf("\n\t\t\t\tSEARCH EQUIPMENT\n");
									line();
									printf("\t\t\t\t1.BY ID\n\t\t\t\t2.BY NAME\n\t\t\t\t3.Equipment Menu\n\t\t\t\t4.Exit\n");
									printf("\t\t\t\tYour option is : ");
									scanf("%d",&s_op);
									switch(s_op)
									{
										case 1:
											clrscr();
											heading();
											ie_search();
											getch();
											goto sea_menu;

										case 2:

											clrscr();
											heading();
											name_search();
											getch();
											goto sea_menu;

										case 3:
											goto equip_menu;

										case 4:
											exit(0);

										default:
											printf("       \t\t\t\"!Please enter valid option !\"\n\n       \t\t\t");
											system("pause");//getch();
											goto sea_menu;

									}

								case 3:
									clrscr();
									heading();
									view();
									getch();
									goto equip_menu;

								case 4:
									clrscr();
									heading();
									printf("\nList of existing equipments is \n ");
									view();
									getch();
									clrscr();
									heading();
									remove_eq();
									getch();
									goto equip_menu;

								case 5:
									goto mainmenu;
								case 6:
									exit(0);
								default :
									printf("       \t\t\t\"!Please enter valid option !\"\n\n       \t\t\t");
									system("pause");//getch();
									goto equip_menu;
							}

						case 4:
							mem_menu:
							clrscr();
							heading();
							line();
							printf("\n\t\t\t\tMEMBERSHIP INFO\n");
							line();
							printf("\t\t\t\t1.Normal Membership\n\t\t\t\t2.Silver Membership\n\t\t\t\t3.Gold Membership \n\t\t\t\t4.Diamond Membership\n\t\t\t\t5.Main Menu\n\t\t\t\t6.Exit\n");
							printf("\t\t\t\tYour option is : ");
							scanf("%d",&m_op);
							switch(m_op)
							{
								case 1:
									clrscr();
									heading();
									normal();
									getch();
									goto mem_menu;

								case 2:
									clrscr();
									heading();
									silver();
									getch();
									goto mem_menu;

								case 3:
									clrscr();
									heading();
									gold();
									getch();
									goto mem_menu;

								case 4:
									clrscr();
									heading();
									diamond();
									getch();
									goto mem_menu;

								case 5:
									goto mainmenu;
								case 6:
									exit(0);
								default :
									printf("       \t\t\t\"!Please enter valid option !\"\n\n       \t\t\t");
									system("pause");//getch();
									goto mem_menu;
							}

						case 5:
							exit(0);

						default:
							printf("       \t\t\t\"!Please enter valid option !\"\n\n       \t\t\t");
							system("pause");//getch();
							clrscr();
							goto mainmenu;
					}
				}
				else
				{
					printf("\n\n\t\t\t\t\"!Please enter valid password !\"\n");
					getch();
					goto login;
				}
			case 2:
				user:
				clrscr();
				heading();
				line();
				printf("\n\t\t\t\tUSER LOGIN\n");
				line();
				printf("\n\t\t\t\tEnter your role : ");
				printf("\n\t\t\t\t1.Trainer\n\t\t\t\t2.Member\n\t\t\t\t3.Exit");
				printf("\n\t\t\t\tEnter you choice : ");
				scanf("%d",&choice);
				switch(choice)
				{
					case 1:
						trainer:
						clrscr();
						heading();
						line();
						printf("\n\t\t\t\tTRAINER\n");
						line();
						printf("\n\t\t\t\t1.Memeber Details\n\t\t\t\t2.Equipment details\n\t\t\t\t3.Back to Menu\n\t\t\t\t4.Exit");
						printf("\n\t\t\t\tEnter you choice : ");
						scanf("%d",&choice);
						switch(choice)
						{
							case 1:
								clrscr();
								heading();
								line();
								printf("List of MEMBERS :\n");
								view_member();
								getch();
								goto trainer;

							case 2:
								clrscr();
								heading();
								line();
								printf("List of EQUIPMENTS :\n");
								view();
								getch();
								goto trainer;

							case 3:
								goto user;

							case 4:
								exit();
							default:
								printf("       \t\t\t\"!Please enter valid option !\"\n\n       \t\t\t");
								system("pause");//getch();
								clrscr();
								goto trainer;
						}

					case 2:
						Member:
						clrscr();
						heading();
						line();
						printf("\n\t\t\t\tMEMBER\n");
						line();
						printf("\n\t\t\t\t1.Trainer Details\n\t\t\t\t2.Membership details\n\t\t\t\t3.Equipment details\n\t\t\t\t4.Contact Info\n\t\t\t\t5.Back to menu\n\t\t\t\t6.Exit");
						printf("\n\t\t\t\tEnter you choice : ");
						scanf("%d",&choice);
						switch(choice)
						{
							case 1:
								clrscr();
								heading();
								line();
								printf("List of TRAINERS :\n");
								view_trainer();
								getch();
								goto Member;

							case 2:
								mem:
								clrscr();
								heading();
								line();
								printf("\n\t\t\t\tMEMBERSHIP INFO\n");
								line();
								printf("\t\t\t\t1.Normal Membership\n\t\t\t\t2.Silver Membership\n\t\t\t\t3.Gold Membership \n\t\t\t\t4.Diamond Membership\n\t\t\t\t5.Member Menu\n\t\t\t\t6.Exit\n");
								printf("\t\t\t\tYour option is : ");
								scanf("%d",&m_op);
								switch(m_op)
								{
									case 1:
										clrscr();
										heading();
										normal();
										getch();
										goto mem;

									case 2:
										clrscr();
										heading();
										silver();
										getch();
										goto mem;

									case 3:
										clrscr();
										heading();
										gold();
										getch();
										goto mem;

									case 4:
										clrscr();
										heading();
										diamond();
										getch();
										goto mem;

									case 5:
										goto Member;
									case 6:
										exit();
									default :
										printf("       \t\t\t\"!Please enter valid option !\"\n\n       \t\t\t");
										system("pause");//getch();
										goto mem;
								}

							case 3:
								clrscr();
								heading();
								line();
								printf("List of EQUIPMENTS :\n");
								view();
								getch();
								goto Member;
							case 4:
								clrscr();
								heading();
								line();
								printf("\n\t\t\t\tCONTACT US\n");
								line();
								printf("\nIN CASE OF ANY QUERY PLEASE CONTACT US. \n");
								printf("\nEMAIL : \t\t\t\tPhone Number : \n\tadmin123@gmail.com\t\t\t\t 1221233212\n\tff1213@gmail.com\t\t\t\t 1234956807\n");
								getch();
								goto Member;

							case 5:
								goto user;
							case 6:
								exit();
							default:
								printf("       \t\t\t\"!Please enter valid option !\"\n\n       \t\t\t");
								system("pause");//getch();
								clrscr();
								goto Member;
						}

					case 3:
						exit();
					default:
						printf("       \t\t\t\"!Please enter valid option !\"\n\n       \t\t\t");
						system("pause");	//getch();
						clrscr();
						goto user;
				}

			case 3:
				exit();
			default:
				printf("       \t\t\t\"!Please enter valid option !\"\n\n       \t\t\t");
				system("pause");
				clrscr();
				goto login;
		}
	//system("pause");
}
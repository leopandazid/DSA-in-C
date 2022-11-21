//Trie houses lower case english alphabets
#include<stdio.h>
#include<stdlib.h>

typedef struct trie
{
	struct trie *child[26];
	int endOfWord;
}TRIE;

TRIE* createNode();
void insert(TRIE *root,char *pattern);
int search(TRIE *root,char *pattern);
TRIE* delete(TRIE *root,char *pattern,int level,int length);
void display(TRIE *root,char *str,int level);
void displayOfLen(TRIE *root,char *str,int level,int length);
void destroy(TRIE *root);

int main()
{
	TRIE *root=createNode();
	
	insert(root,"ant");
	insert(root,"apple");
	insert(root,"app");
	insert(root,"bag");
	
	if(search(root,"ant"))
		printf("ant present\n");
	else
		printf("ant not present\n");
	
	if(search(root,"apple"))
		printf("apple present\n");
	else
		printf("apple not present\n");
	
	if(search(root,"app"))
		printf("app present\n");
	else
		printf("app not present\n");
	
	if(search(root,"bag"))
		printf("bag present\n");
	else
		printf("bag not present\n");
	
	if(search(root,"an"))
		printf("an present\n");
	else
		printf("an not present\n");
	
	delete(root,"app",0,3);
 	if(search(root,"app"))
		printf("app present\n");
	else
		printf("app not present\n"); 
	
	char str[100];
	printf("Patterns present in the trie data structure\n");
	display(root,str,0);
	
	printf("Patterns of length 3\n");
	displayOfLen(root,str,0,3);
	destroy(root);
	free(root);
}


TRIE* createNode()
{
	TRIE *newNode=malloc(sizeof(TRIE));
	for(int i=0;i<26;i++)
		newNode->child[i]=NULL;
	newNode->endOfWord=0;
	
	return newNode;
}

void insert(TRIE *root,char *pattern)
{
	int index;
	while(*pattern)
	{
		index=*pattern-'a';
		if(root->child[index]==NULL)
			root->child[index]=createNode();
		root=root->child[index];
		pattern++;
	}
	root->endOfWord=1;
}
int search(TRIE *root,char *pattern)
{
	int index;
	while(*pattern)
	{
		index=*pattern-'a';
		if(root->child[index]==NULL)
			return 0;
		root=root->child[index];
		pattern++;
	}
	return root->endOfWord;
}
int isEmpty(TRIE *root)
{
	for(int i=0;i<26;i++)
	{
		if(root->child[i]!=NULL)
			return 0;
	}
	return 1;
}
TRIE* delete(TRIE *root,char *pattern,int level,int length)
{
	if(length==level)
	{
		if(root->endOfWord==1)
			root->endOfWord=0;
		if(isEmpty(root))
		{
			free(root);
			root=NULL;
		}
		return root;
	}
	int index=pattern[level]-'a';
	root->child[index]=delete(root->child[index],pattern,level+1,length);
	if(root->endOfWord==0 &&isEmpty(root))
	{
		free(root);
		root=NULL;
	}
	return root;
}

void destroy(TRIE *root)
{
	for(int i=0;i<26;i++)
	{
		if(root->child[i]!=NULL)
		{
			destroy(root->child[i]);
//			printf("%c freed\n",i+'a');
			free(root->child[i]);
			root->child[i]=NULL;
		}
	}
}

void display(TRIE *root,char *str,int level)
{
	if(root->endOfWord)
	{
		str[level]='\0';
		printf("%s\n",str);
	}
	for(int i=0;i<26;i++)
	{
		if(root->child[i]!=NULL)
		{
			str[level]=i+'a';
			display(root->child[i],str,level+1);
		}
	}
}

void displayOfLen(TRIE *root,char *str,int level,int length)
{
	if(root->endOfWord && length==level)
	{
		str[level]='\0';
		printf("%s\n",str);
	}
	for(int i=0;i<26;i++)
	{
		if(root->child[i]!=NULL)
		{
			str[level]=i+'a';
			displayOfLen(root->child[i],str,level+1,length);
		}
	}	
}
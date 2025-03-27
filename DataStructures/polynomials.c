#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
	int coefficient;
	int exponent;
	struct node *link;
};
struct node *create(struct node *);
struct node *addatbeg(struct node *, int, int);
struct node *addatend(struct node *, int, int);
void display(struct node *ptr);
void poly_add(struct node *, struct node *);
void poly_mul(struct node *, struct node *);
struct node *addatpos(struct node *, int, int, int);
void modify_poly(struct node *);
struct node *del(struct node *, int, int);
struct node *create_from_file(struct node *t, FILE *);

int main()
{
	struct node *poly1 = NULL, *poly2 = NULL;
	printf("Enter polynomial 1: \n");
	poly1 = create(poly1);
	printf("Enter polynomial 2: \n");
	poly2 = create(poly2);

	int choice, j;
	char str[20];
	while (1)
	{
		printf("\n1 - Modify Polynomial\n");
		printf("2 - Add the two polynomials\n");
		printf("3 - Multiply two polynomials\n");
		printf("4 - Take polynomial from the file\n");
		printf("5 - Exit the program\n");
		printf("Enter your choice - ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
		{
			printf("The polynomial that you want to modify is -\n");
			printf("Polynomial 1  = ");
			display(poly1);
			printf("Polynomial 2  = ");
			display(poly2);
		a:
			printf("Your choice (1 or 2) = ");
			scanf("%d", &j);
			if (j == 1)
			{
				modify_poly(poly1);
			}
			else if (j == 2)
			{
				modify_poly(poly2);
			}
			else
			{
				printf("Invalid Input\nRe-Enter ");
				goto a;
				break;
			}
		}
		case 2:
		{
			printf("\nPolynomial 1 is : ");
			display(poly1);
			printf("\nPolynomial 2 is : ");
			display(poly2);
			poly_add(poly1, poly2);
			break;
		}
		case 3:
		{
			printf("\nPolynomial 1 is : ");
			display(poly1);
			printf("\nPolynomial 2 is : ");
			display(poly2);
			poly_mul(poly1, poly2);
			break;
		}
		case 4:
		{
			struct node *start1 = NULL;
			struct node *start2 = NULL;
            FILE *fp;
            fp = fopen("Poly.txt.txt", "r");
            start1 = create_from_file(start1, fp);
            start2 = create_from_file(start2, fp);
            printf("Plynomial expression 1: ");
            display(start1);
            printf("\nPolynomial expression 2: ");
            display(start2);
            fclose(fp);
            break;
		}
		case 5:
		{
			printf("Program Terminated.\n");
			exit(1);
		}
		}
	}
}

struct node *create(struct node *poly)
{
	int i, n, coe, exp;
	printf("Enter the number of terms: ");
	scanf("%d", &n);
	poly = NULL;
	if (n == 0)
	{
		return poly;
	}
	printf("Enter coefficient for term %d: ", i + 1);
	scanf("%d", &coe);
	printf("Enter exponent for term %d: ", i + 1);
	scanf("%d", &exp);
	poly = addatbeg(poly, coe, exp);
	for (i = 1; i < n; i++)
	{
		printf("Enter coefficient for term %d: ", i + 1);
		scanf("%d", &coe);
		printf("Enter exponent for term %d: ", i + 1);
		scanf("%d", &exp);
		poly = addatend(poly, coe, exp);
	}
	return poly;
}

struct node *addatbeg(struct node *poly, int coe, int exp)
{
	struct node *ptr, *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->coefficient = coe;
	tmp->exponent = exp;

	if (poly == NULL || exp > poly->exponent)
	{
		tmp->link = poly;
		poly = tmp;
	}
	else
	{
		ptr = poly;
		while (ptr->link != NULL && ptr->link->exponent >= exp)
		{
			ptr = ptr->link;
			tmp->link = ptr->link;
			ptr->link = tmp;
		}
	}
	return poly;
}

struct node *addatend(struct node *poly, int coe, int exp)
{
	struct node *ptr, *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->coefficient = coe;
	tmp->exponent = exp;
	if (poly == NULL)
	{
		tmp->link = poly;
		poly = tmp;
	}
	else
	{
		ptr = poly;
		while (ptr->link != NULL)
		{
			ptr = ptr->link;
		}
		tmp->link = ptr->link;
		ptr->link = tmp;
	}
	return poly;
}

void display(struct node *ptr)
{
	if (ptr == NULL)
	{
		printf("Zero polynomial\n");
		return;
	}
	while (ptr != NULL)
	{
		printf("%dx^%d", ptr->coefficient, ptr->exponent);
		ptr = ptr->link;
		if (ptr != NULL)
		{
			printf(" + ");
		}
		else
		{
			printf("\n");
		}
	}
}

void poly_add(struct node *p1, struct node *p2)
{
	struct node *poly3;
	poly3 = NULL;
	while (p1 != NULL && p2 != NULL)
	{
		if (p1->exponent > p2->exponent)
		{
			poly3 = addatend(poly3, p1->coefficient, p1->exponent);
			p1 = p1->link;
		}
		else if (p2->exponent > p1->exponent)
		{
			poly3 = addatend(poly3, p2->coefficient, p2->exponent);
			p2 = p2->link;
		}
		else if (p1->exponent == p2->exponent)
		{
			poly3 = addatend(poly3, p1->coefficient + p2->coefficient, p1->exponent);
			p1 = p1->link;
			p2 = p2->link;
		}
	}

	while (p1 != NULL)
	{
		poly3 = addatend(poly3, p1->coefficient, p1->exponent);
		p1 = p1->link;
	}

	while (p2 != NULL)
	{
		poly3 = addatend(poly3, p2->coefficient, p2->exponent);
		p2 = p2->link;
	}
	printf("\nAdded polynomial is: ");
	display(poly3);
}

void poly_mul(struct node *p1, struct node *p2)
{
	struct node *poly3;
	struct node *p2_beg = p2;

	poly3 = NULL;
	if (p1 == NULL || p2 == NULL)
	{
		printf("Multiplied polynomial is a zero polynomial\n");
		return;
	}
	while (p1 != NULL)
	{
		p2 = p2_beg;
		while (p2 != NULL)
		{
			poly3 = addatend(poly3, p1->coefficient * p2->coefficient, p1->exponent + p2->exponent);
			p2 = p2->link;
		}
		p1 = p1->link;
	}
	printf("\nMultiplied polynomial is: ");
	display(poly3);
}

void modify_poly(struct node *p)
{
	int c, co, ex, pos;
	while (c != 3)
	{
		printf("1. Insert a new term\n");
		printf("2. Delete a term\n");
		printf("3. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
		{
			printf("Enter the coefficient to be inserted: ");
			scanf("%d", &co);
			printf("Enter the exponent to be inserted: ");
			scanf("%d", &ex);
			printf("Enter the position at which to insert: ");
			scanf("%d", &pos);
			p = addatpos(p, co, ex, pos);
			display(p);
			break;
		}
		case 2:
		{
			printf("Enter the coefficient of the term to be deleted: ");
			scanf("%d", &co);
			printf("Enter the exponent of the term to be deleted: ");
			scanf("%d", &ex);
			p = del(p, co, ex);
			display(p);
			break;
		}
		case 3:
		{
			printf("Program Terminated.\n");
			exit(1);
		}
		}
	}
}

struct node *addatpos(struct node *p, int co, int ex, int pos)
{
	struct node *tmp, *start;
	int i;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->coefficient = co;
	tmp->exponent = ex;
	if (pos == 1)
	{
		tmp->link = start;
		start = tmp;
		return start;
	}
	start = p;
	for (i = 1; i < pos - 1 && p != NULL; i++)
	{
		start = start->link;
	}

	if (start == NULL)
	{
		printf("There are less than %d elements\n", pos);
	}
	else
	{
		tmp->link = p->link;
		start->link = tmp;
	}
	return p;
}

struct node *del(struct node *p, int co, int ex)
{
	struct node *tmp, *start;
	if (p == NULL)
	{
		printf("List is empty\n");
		return start;
	}
	if (p->coefficient == co && p->exponent == ex)
	{
		tmp = p;
		p = p->link;
		free(tmp);
		return p;
	}
	start = p;
	while (start->link != NULL)
	{
		if (start->link->coefficient == co && start->link->exponent == ex)
		{
			tmp = start->link;
			start->link = tmp->link;
			free(tmp);
			return p;
		}
		start = start->link;
	}
	return start;
}

struct node *create_from_file(struct node *start, FILE *fp)
{
    struct node *temp, *p;
    int n,i;
    fscanf(fp, "%d ", &n);
    for ( i = 0; i < n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        fscanf(fp, "%d %d ", &temp->coefficient, &temp->exponent);
        temp->link = NULL;
        if (start == NULL)
            start = temp;
        else
        {
            p = start;
            while (p->link != NULL)
                p = p->link;
            p->link = temp;
        }
    }
    return start;
}

	

void read_graph_from_file(edgeTo **adj[], int *num_nodes, int weighted, int directed,  FILE * f) {
    
    int v=0;
    int counter = 0, from=0, to=0;
    while (fscanf(f, "%d", &v) == 1) {
        if (counter == 0){    
            *num_nodes = v;
            //printf("num of nodes = %d\n", *num_nodes);
            *adj = malloc(*num_nodes * sizeof(edgeTo)); 
            counter ++;
        }
        else if ( (counter >= 1) && (counter <= *num_nodes)) {
            counter++;
        }
        else {
            from = v;
            fscanf(f, "%d", &to);
            //printf("counter:%d  from:%d  to:%d\n", counter, from, to);           
            counter++;
            //if (weighted == 1)
            //read the edge weight
            int w=1;    
            if ( weighted == 1)    
                fscanf(f, "%d", &w);

            add_edge(*adj, *num_nodes, from, to, w);

            //if the graph is not directed, then add the edge
            //to both node's lists
            if (directed == 0) 
                add_edge(*adj, *num_nodes, to, from, w);
        }
    }
}

void depth_first_search_recursive_auxiliary(edgeTo *adj[], int size, int visited[], int start) {

    edgeTo *neighbors = adj[start];
    visited[start] = 1;
    printf("%d ", start);
    while (neighbors!= NULL) {
        int n = neighbors->toNode;
        if (visited[n] == 0 )
            depth_first_search_recursive_auxiliary(adj, size, visited, n);
        neighbors = neighbors->next;
    }
}

void depth_first_search_recursive(edgeTo *adj[], int size, int start) {
    int visited[size];
    int i;
    for (i=0; i<size; i++)
        visited[i] = 0;
    depth_first_search_recursive_auxiliary(adj, size, visited, start);
}

void depth_first_search_iterative(edgeTo *adj[], int size, int start) {

    int visited[size];
    int i;
    
    for (i=0; i<size; i++)
        visited[i] = 0;

    Stack S;
    S = CreateStack(20);
    Push(S, start);

    visited[start] = 1;
    edgeTo *p = NULL;

    while (!IsEmpty(S)) {
        int node = TopOfStack(S);
        Pop(S);
        visited[node] = 1;
        printf("%d ", node);
        p = adj[node];

        while (p!= NULL) {
            i = p->toNode;
            if (visited[i] == 0) {
                visited[i] = 1;
                Push(S, i);
            }
            p = p->next;
        }    
    }
}

void breadth_first_search_recursive_aux(edgeTo *adj[], int size, int *visited, Queue q) {
    int i;
    edgeTo *p = NULL;

    if (IsEmptyQueue(q) )
        return;

    int node = Front(q);
    visited[node] = 1;
    printf("%d ", node);
    p = adj[node];
    Dequeue( q);
    while (p!= NULL) {
        i = p->toNode;
        if (visited[i] == 0) {
            visited[i] = 1;
            Enqueue(i, q);
        }
        p = p->next;
    }
    breadth_first_search_recursive_aux(adj, size, visited, q);
}

void breadth_first_search_recursive(edgeTo *adj[], int size, int start) {
    int visited[size];
    int i;
    Queue q;
    q = CreateQueue();
    Enqueue(start, q);

    for (i=0; i<size; i++)
        visited[i] = 0;

    breadth_first_search_recursive_aux(adj, size, visited, q);
}

void breadth_first_search_iterative_aux(edgeTo *adj[], int size, int visited[], int start) {
    int i;
    Queue q;
    q = CreateQueue();
    Enqueue(start, q);

    visited[start] = 1;
    edgeTo *p = NULL;

    while (!IsEmptyQueue(q)) {
        int node = Front(q);
        visited[node] = 1;
        printf("%d ", node);
        p = adj[node];

        Dequeue( q);
        while (p!= NULL) {
            i = p->toNode;
            if (visited[i] == 0) {
                visited[i] = 1;
                Enqueue(i, q);
            }
            p = p->next;
        }    
    }
}

void breadth_first_search_iterative(edgeTo *adj[], int size, int start) {

    int visited[size];
    int i;
    
    for (i=0; i<size; i++)
        visited[i] = 0;

    breadth_first_search_iterative_aux(adj, size, visited, start);
}

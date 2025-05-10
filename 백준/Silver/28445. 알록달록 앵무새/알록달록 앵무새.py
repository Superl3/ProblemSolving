papa = input().split()
mama = input().split()

genes = sorted(set(papa+mama))

def get_child_genes(depth, child_genes, genes):
    if depth == 2:
        for gene in child_genes:
            print(gene, end=' ')
        print()
        return
    for gene in genes:
        child_genes.append(gene)
        get_child_genes(depth+1, child_genes, genes)
        child_genes.pop()

get_child_genes(0, [], genes);